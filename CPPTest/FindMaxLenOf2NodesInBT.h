#ifndef _FIND_MAX_LEN_
#define _FIND_MAX_LEN_

// 数据结构定义
struct Node
{
	char chValue = 0;//该节点的值
	Node* pLeft;
	Node* pRight;
	int nMaxLDepth;
	int nMaxRDepth;

	Node(char value):
		chValue(value), nMaxLDepth(0), nMaxRDepth(0)
	{
	}
};

int nNodeValue = 0;
int nMaxLen = 0;

void findMaxLen(Node* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	if (pRoot->pLeft == nullptr)
	{
		pRoot->nMaxLDepth = 0;
	}
	else
	{
		findMaxLen(pRoot->pLeft);
		pRoot->nMaxLDepth = (pRoot->pLeft->nMaxLDepth > pRoot->pLeft->nMaxRDepth ? pRoot->pLeft->nMaxLDepth : pRoot->pLeft->nMaxRDepth) + 1;
	}

	if (pRoot->pRight == nullptr)
	{
		pRoot->nMaxRDepth = 0;
	}
	else
	{
		findMaxLen(pRoot->pRight);
		pRoot->nMaxRDepth = (pRoot->pRight->nMaxLDepth > pRoot->pRight->nMaxRDepth ? pRoot->pRight->nMaxLDepth : pRoot->pRight->nMaxRDepth) + 1;
	}

	if (pRoot->nMaxLDepth + pRoot->nMaxRDepth > nMaxLen)
	{
		nNodeValue = pRoot->chValue;
		nMaxLen = pRoot->nMaxLDepth + pRoot->nMaxRDepth;
	}

}

#endif // DEBUG