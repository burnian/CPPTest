#include "SparseGraph.h"


const GraphNode& SparseGraph::getNode(int idx)const {
	GraphNode pNode = m_Nodes[idx];
	return m_Nodes.at(idx);
}

// 得到一个边的引用
GraphEdge& getEdge(int from, int to)const;
// 取得下一个可用的节点索引
int getNextFreeNodeIndex()const;
// 添加一个节点到图中并返回其索引
int addNode(GraphNode node);
// 删除一个节点
void removeNode(int node);
// 添加和删除边的方法
void addEdge(GraphEdge edge);
void removeEdge(int from, int to);
// 返回当前图中活动的和不活动的节点数
int numNodes()const;
// 返回当前图中活动的节点数
int numActiveNodes()const;
// 返回当前图中的边数
int numEdges()const;

// 图是否有向
bool SparseGraph::isDigraph()const {
	return m_bDigraph;
}

bool SparseGraph::Graph_SearchBFS(int startIndex , int endIndex) {
	std::queue<const GraphEdge*> queEdge;
	// 创建一个哑边放入队列
	GraphEdge dummy(startIndex, startIndex, 0);
	queEdge.push(&dummy);
	bool visited = ;
	std::vector<int> route;
	// 队列中有边时继续搜索
	while (!queEdge.empty())
	{
		const GraphEdge* next = queEdge.front();
		queEdge.pop();
		//标记这个节点的父节点
		route[next->to()] = next->from();
		if (next->to() == endIndex) {
			return true;
		}
		
		m_Edges[next->from]
		for each (auto edge in m_Edges)
		{
			if(edge.
		}

	}
}
