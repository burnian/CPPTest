#pragma once
#include <vector>
#include <map>
#include <math.h>

// б����
#define OBLIQUE_COST (14)
// ��������
#define ORTHOGONAL_COST (10)

// ��������
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

// ��ͼ��
struct Tile
{
	Vec2 pos;
	Tile* parent;
	size_t startCost; // ��㵽�õ�ĵ�ǰ·������
	size_t endCost; // �õ㵽�յ������·������
	size_t evaluation; // �õ�����ֵ eval=startCost+endCost
};


class IAStar
{
public:
	IAStar();
	IAStar(size_t width, size_t height);
	~IAStar();

	// ��ʼ����ͼ
	void init(size_t width, size_t height, const std::vector<Vec2>& blocks);
	// ���ش�endPos��startPos�������ߵĵ��б�
	std::vector<Vec2>* findPath(const Vec2& start, const Vec2& end);

private:
	// �����������꣨x,y����0��ʼ���õ�Ψһ����
	inline size_t getIndex(int x, int y);
	// ��ֵ������open�й�ֵ��С��tile��������һ�����
	size_t evaluate(Vec2& point);
	// �жϸõ��Ƿ�Ϊ�ϰ���
	bool isBlock(int x, int y);
	// ������ǰ���tile���ڽ�tile������������Ϣ
	bool visitNearPoints(Tile* pTile, const Vec2& end);
	// �������
	void clear();
	// ���ĳ����������ϰ�����Сcost
	size_t getTwoPointsLeastCost(const Vec2& pointA, const Vec2& pointB);


	// ��ͼ����x���������
	size_t _width;
	// y���������
	size_t _height;
	// �����tile�б�
	std::map<size_t, Tile*> _openMap;
	// �Ѽ��tile�б�
	std::map<size_t, Tile*> _closeMap;
	// ��ͼ�ڵؿ����� 0���У�1�ϰ�
	std::vector<char> _blocks;
};

