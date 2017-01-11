#include "IAStar.h"


IAStar::IAStar()
	: _width(0), _height(0)
{
}

IAStar::IAStar(size_t width, size_t height)
	: _width(width), _height(height)
{
	_blocks.resize(width * height);
}

IAStar::~IAStar()
{
	clear();
}

void IAStar::init(size_t width, size_t height, const std::vector<Vec2>& blocks)
{
	clear();
	_width = width;
	_height = height;
	_blocks.resize(width * height);
	for each (Vec2 point in blocks)
	{
		_blocks[getIndex(point.x, point.y)] = 1;
	}
}

std::vector<Vec2>* IAStar::findPath(const Vec2& start, const Vec2& end)
{
	std::vector<Vec2>* pPath = new std::vector<Vec2>();
	Tile *startTile = new Tile();
	startTile->pos = start;
	startTile->parent = nullptr;
	startTile->startCost = 0;
	startTile->endCost = 0;
	startTile->evaluation = 0;
	_openMap[getIndex(startTile->pos.x, startTile->pos.y)] = startTile;
	while (!_openMap.empty())
	{
		std::map<size_t, Tile*>::iterator it = _openMap.begin();
		Tile *pMin = it->second;
		for (++it; it != _openMap.end(); ++it)
		{
			if (pMin->evaluation > it->second->evaluation)
			{
				pMin = it->second;
			}
		}
		if (visitNearPoints(pMin, end))
		{
			pPath->push_back(end);
			while (pMin != nullptr)
			{
				pPath->push_back(pMin->pos);
				pMin = pMin->parent;
			}
			return pPath;
		}
	}
	return pPath;
}

size_t IAStar::getIndex(int x, int y)
{
	return x + y*_width;
}

bool IAStar::isBlock(int x, int y)
{
	return x < 0 || x >= _width || y < 0 || y >= _height || _blocks[x + y*_width];
}

bool IAStar::visitNearPoints(Tile* pTile, const Vec2& end)
{
	int tempX = 0;
	int tempY = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i==0 && j==0)
			{
				continue;
			}
			tempX = pTile->pos.x + i;
			tempY = pTile->pos.y + j; 
			// 遇见终点
			if (end.x == tempX && end.y == tempY)
			{
				return true;
			}
			if (!isBlock(tempX, tempY))
			{
				size_t index = getIndex(tempX, tempY);
				std::map<size_t, Tile*>::iterator it;
				it = _closeMap.find(index);
				if (_closeMap.end() != it)
				{
					continue;
				}
				// 更新相邻tile信息
				size_t cost = abs(i) == abs(j) ? OBLIQUE_COST : ORTHOGONAL_COST;
				it = _openMap.find(index);
				if (_openMap.end() == it)
				{
					// 初始化并加入open
					Tile *pTemp= new Tile();
					pTemp->pos = Vec2(tempX, tempY);
					pTemp->parent = pTile;
					pTemp->startCost = pTile->startCost + cost;
					pTemp->endCost = getTwoPointsLeastCost(end, pTemp->pos);
					pTemp->evaluation = pTemp->startCost + pTemp->endCost;
					_openMap[index] = pTemp;
				}
				else
				{
					// 更新
					Tile* pTemp = _openMap[index];
					if (pTemp->startCost > pTile->startCost + cost)
					{
						pTemp->parent = pTile;
						pTemp->startCost = pTile->startCost + cost;
						pTemp->evaluation = pTemp->startCost + pTemp->endCost;
					}
				}
			}
		}
	}
	size_t index = getIndex(pTile->pos.x, pTile->pos.y);
	_openMap.erase(index);
	_closeMap[index] = pTile;
	return false;
}


void IAStar::clear()
{
	for each (auto v in _openMap)
	{
		delete(v.second);
	}
	for each (auto v in _closeMap)
	{
		delete(v.second);
	}
	_blocks.clear();
	_openMap.clear();
	_closeMap.clear();
}

size_t IAStar::getTwoPointsLeastCost(const Vec2& pointA, const Vec2& pointB)
{
	size_t deltaX = abs(pointA.x - pointB.x);
	size_t deltaY = abs(pointA.y - pointB.y);
	size_t maximun = deltaX > deltaY ? deltaX : deltaY;
	size_t minimun = deltaX > deltaY ? deltaY : deltaX;
	return ORTHOGONAL_COST*(maximun - minimun) + OBLIQUE_COST*minimun;
}
