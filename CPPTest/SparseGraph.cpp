#include "SparseGraph.h"


const GraphNode& SparseGraph::getNode(int idx)const {
	GraphNode pNode = m_Nodes[idx];
	return m_Nodes.at(idx);
}

// �õ�һ���ߵ�����
GraphEdge& getEdge(int from, int to)const;
// ȡ����һ�����õĽڵ�����
int getNextFreeNodeIndex()const;
// ���һ���ڵ㵽ͼ�в�����������
int addNode(GraphNode node);
// ɾ��һ���ڵ�
void removeNode(int node);
// ��Ӻ�ɾ���ߵķ���
void addEdge(GraphEdge edge);
void removeEdge(int from, int to);
// ���ص�ǰͼ�л�ĺͲ���Ľڵ���
int numNodes()const;
// ���ص�ǰͼ�л�Ľڵ���
int numActiveNodes()const;
// ���ص�ǰͼ�еı���
int numEdges()const;

// ͼ�Ƿ�����
bool SparseGraph::isDigraph()const {
	return m_bDigraph;
}

bool SparseGraph::Graph_SearchBFS(int startIndex , int endIndex) {
	std::queue<const GraphEdge*> queEdge;
	// ����һ���Ʊ߷������
	GraphEdge dummy(startIndex, startIndex, 0);
	queEdge.push(&dummy);
	bool visited = ;
	std::vector<int> route;
	// �������б�ʱ��������
	while (!queEdge.empty())
	{
		const GraphEdge* next = queEdge.front();
		queEdge.pop();
		//�������ڵ�ĸ��ڵ�
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
