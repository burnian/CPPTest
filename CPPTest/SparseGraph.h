#pragma once
#include <vector>
#include <list>
#include <queue>


class GraphNode
{
protected:
	// �ڵ�����
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
	// һ�������������ڵ�
	int m_iFrom;
	int m_iTo;
	// �����˱�����Ŀ���
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
	// һЩ���õ����Ͷ���
	typedef std::vector<GraphNode> NodeVector;
	typedef std::list<GraphEdge> EdgeList;
	typedef std::vector<EdgeList> EdgeListVector;
private:
	// ������ͼ�����нڵ�
	NodeVector m_Nodes;
	// һ���ߵĶ�̬���飨ͨ���ڵ�������������Ըýڵ�Ϊ���ı��б��������
	EdgeListVector m_Edges;
	// �Ƿ�����ͼ
	bool m_bDigraph;

	// ��Ҫ����ӵ���һ���ڵ��������
	int m_iNextNodeIndex;
public:
	SparseGraph(bool digraph = false):m_iNextNodeIndex(0) , m_bDigraph(digraph){}
	// ���ظ��������Ľڵ�
	const GraphNode& getNode(int idx)const;
	// �õ�һ���ߵ�����
	GraphEdge& getEdge(int from, int to)const;
	// ȡ����һ�����õĽڵ�����
	int getNextFreeNodeIndex()const;
	// ���һ���ڵ㵽ͼ�в�����������
	int addNode(GraphNode node) { m_Nodes.push_back(node); };
	// ɾ��һ���ڵ�
	void removeNode(int idx) { m_Nodes.erase(idx); };
	// ��Ӻ�ɾ���ߵķ���
	void addEdge(GraphEdge edge);
	void removeEdge(int from, int to);
	// ���ص�ǰͼ�л�ĺͲ���Ľڵ���
	int numNodes()const;
	// ���ص�ǰͼ�л�Ľڵ���
	int numActiveNodes()const;
	// ���ص�ǰͼ�еı���
	int numEdges()const { return m_Edges.size(); };

	// ͼ�Ƿ�����
	bool isDigraph()const { return m_bDigraph; }
	// ���ͼ��û�нڵ㣬����true
	bool isEmpty()const { return m_Nodes.empty(); }
	// ��һ���ڵ���ͼ�д��ڣ�����true
	bool isPresent(int idx)const;

	// �����������
	bool Graph_SearchBFS(int startIndex, int endIndex);
};

