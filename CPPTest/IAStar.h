#pragma once
#include <vector>
#include <map>
#include <math.h>

// 斜方向
#define OBLIQUE_COST (14)
// 正交方向
#define ORTHOGONAL_COST (10)

// 网格坐标
class Vec2
{
public:
	Vec2() :
		x(0), y(0)
	{};
	Vec2(int x, int y):
		x(x), y(y)
	{};

	Vec2* operator=(const Vec2& vec)
	{
		x = vec.x;
		y = vec.y;
		return this;
	};

	//bool operator==(const Vec2& vec)
	//{
	//	return x == vec.x && y == vec.y;
	//};

public:
	int x;
	int y;
};

// 地图块
struct Tile
{
	Vec2 pos;
	Tile* parent;
	size_t startCost; // 起点到该点的当前路径代价
	size_t endCost; // 该点到终点的最优路径代价
	size_t evaluation; // 该点评估值 eval=startCost+endCost
};


class IAStar
{
public:
	IAStar();
	IAStar(size_t width, size_t height);
	~IAStar();

	// 初始化地图
	void init(size_t width, size_t height, const std::vector<Vec2>& blocks);
	// 返回从endPos到startPos可以行走的点列表
	std::vector<Vec2>* findPath(const Vec2& start, const Vec2& end);

private:
	// 根据网格坐标（x,y都从0开始）得到唯一索引
	inline size_t getIndex(int x, int y);
	// 估值函数，open中估值最小的tile将进行下一步检测
	size_t evaluate(Vec2& point);
	// 判断该点是否为障碍点
	bool isBlock(int x, int y);
	// 遍历当前检测tile的邻接tile，并更新其信息
	bool visitNearPoints(Tile* pTile, const Vec2& end);
	// 清空数据
	void clear();
	// 获得某两点间无视障碍的最小cost
	size_t getTwoPointsLeastCost(const Vec2& pointA, const Vec2& pointB);


	// 地图网格x方向格子数
	size_t _width;
	// y方向格子数
	size_t _height;
	// 待检测tile列表
	std::map<size_t, Tile*> _openMap;
	// 已检测tile列表
	std::map<size_t, Tile*> _closeMap;
	// 地图内地块属性 0可行，1障碍
	std::vector<char> _blocks;
};

