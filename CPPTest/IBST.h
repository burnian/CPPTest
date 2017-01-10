#pragma once
#include <functional>

// BST���ڵ�
template<class T>
class BSTNode
{
public:
	BSTNode() :lChild(nullptr), rChild(nullptr), freq(1) {};

public:
	BSTNode<T>* lChild;
	BSTNode<T>* rChild;
	T data;
	size_t freq;
};

// BST
template<class T>
class IBST
{
public:
	IBST() :_root(nullptr) {};

	// ����
	void insert(T value);
	// ɾ��
	void remove(T value);
	// ����
	BSTNode<T>* find(T value);
	// ����
	void traverse(std::function<void(BSTNode<T>* node)> func);

private:
	void _insert(BSTNode<T>* &node, T value);
	void _remove(BSTNode<T>* &node, T value);
	BSTNode<T>* _find(BSTNode<T>* node, T value);
	void _midOrder(BSTNode<T>* node, std::function<void(BSTNode<T>* node)> func);

private:
	BSTNode<T>* _root;
};



// ����
template<class T>
void IBST<T>::traverse(std::function<void(BSTNode<T>* node)> func)
{
	_midOrder(_root, func);
}

// ����
template<class T>
BSTNode<T>* IBST<T>::find(T value)
{
	_find(_root, value);
}

// ɾ��
template<class T>
void IBST<T>::remove(T value)
{
	_remove(_root, value);
}

// ����
template<class T>
void IBST<T>::insert(T value)
{
	_insert(_root, value);
}

// �������
template<class T>
void IBST<T>::_midOrder(BSTNode<T>* node, std::function<void(BSTNode<T>* node)> func)
{
	if (node == nullptr)
	{
		return;
	}
	_midOrder(node->lChild, func);
	func(node);
	_midOrder(node->rChild, func);
}

template<class T>
BSTNode<T>* IBST<T>::_find(BSTNode<T>* node, T value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (value < node->data)
	{
		_find(node->lChild, value);
	}
	else if (value > node->data)
	{
		_find(node->rChild, value);
	}
	else
	{
		return node;
	}
}

template<class T>
void IBST<T>::_remove(BSTNode<T>* &node, T value)
{
	if (node == nullptr)
	{
		return;
	}
	if (value < node->data)
	{
		_remove(node->lChild, value);
	}
	else if (value > node->data)
	{
		_remove(node->rChild, value);
	}
	else
	{
		if (node->lChild && node->rChild) // ����2���ӽڵ�
		{
			BSTNode<T>* temp = node->rChild;
			while (temp->lChild != nullptr)
			{
				temp = temp->lChild;
			}
			node->data = temp->data;
			node->freq = temp->freq;
			_remove(node->rChild, temp->data);
		}
		else // �ӽڵ�����2��
		{
			BSTNode<T>* temp = node;
			if (node->lChild == nullptr)
			{
				node = node->rChild;
			}
			else
			{
				node = node->lChild;
			}
			delete(temp);
		}
	}
}

template<class T>
void IBST<T>::_insert(BSTNode<T>* &node, T value)
{
	if (node == nullptr)
	{
		node = new BSTNode<T>();
		node->data = value;
		return;
	}
	if (value < node->data)
	{
		_insert(node->lChild, value);
	}
	else if (value > node->data)
	{
		_insert(node->rChild, value);
	}
	else
	{
		++node->freq;
	}
}
