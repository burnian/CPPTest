#pragma once
#include <vector>
#include <list>
#include <queue>


class GraphNode
{
protected:
	// 节点索引
	int m_iIndex;
public:
	GraphNode(int idx) :m_iIndex(idx), m_bVisited(false) {};
	int index()const { return m_iIndex; };
	void setIndex(int newIdx) { m_iIndex = newIdx; };
	void setVisited(bool flag) { m_bVisited = flag; };
};

class GraphEdge
{
protected:
	// 一个边连接两个节点
	int m_iFrom;
	int m_iTo;
	// 经过此边所需的开销
	double m_dCost;
public:
	GraphEdge(int from, int to, double cost = 0) :
		m_iFrom(from),
		m_iTo(to),
		m_dCost(cost) {};
	int from()const { return m_iFrom; };
	void setFrom(int newIdx) { m_iFrom = newIdx; };
	int to()const { return m_iTo; };
	void setTo(int newIdx) { m_iTo = newIdx; };
	double cost()const { return m_dCost; };
	void setCost(double newCost) { m_dCost = newCost; };
};


class SparseGraph
{
public:
	// 一些有用的类型定义
	typedef std::vector<GraphNode> NodeVector;
	typedef std::list<GraphEdge> EdgeList;
	typedef std::vector<EdgeList> EdgeListVector;
private:
	// 组成这个图的所有节点
	NodeVector m_Nodes;
	// 一个边的动态数组（通过节点的索引号来和以该节点为起点的边列表相关联）
	EdgeListVector m_Edges;
	// 是否有向图
	bool m_bDigraph;

	// 将要被添加的下一个节点的索引号
	int m_iNextNodeIndex;
public:
	SparseGraph(bool digraph = false):m_iNextNodeIndex(0) , m_bDigraph(digraph){}
	// 返回给定索引的节点
	const GraphNode& getNode(int idx)const;
	// 得到一个边的引用
	GraphEdge& getEdge(int from, int to)const;
	// 取得下一个可用的节点索引
	int getNextFreeNodeIndex()const;
	// 添加一个节点到图中并返回其索引
	int addNode(GraphNode node) { m_Nodes.push_back(node); };
	// 删除一个节点
	void removeNode(int idx) { m_Nodes.erase(idx); };
	// 添加和删除边的方法
	void addEdge(GraphEdge edge);
	void removeEdge(int from, int to);
	// 返回当前图中活动的和不活动的节点数
	int numNodes()const;
	// 返回当前图中活动的节点数
	int numActiveNodes()const;
	// 返回当前图中的边数
	int numEdges()const { return m_Edges.size(); };

	// 图是否有向
	bool isDigraph()const { return m_bDigraph; }
	// 如果图中没有节点，返回true
	bool isEmpty()const { return m_Nodes.empty(); }
	// 当一个节点在图中存在，返回true
	bool isPresent(int idx)const;

	// 广度优先搜索
	bool Graph_SearchBFS(int startIndex, int endIndex);
};

