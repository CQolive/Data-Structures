#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"
typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTDataType));
	if (pNewNode == NULL)
	{
		assert(0);
		return 0;
	}
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	pNewNode->_data = data;
	return pNewNode;
}
// 二叉树的创建 
BTNode* _CreateBinTree(BTDataType* array, int size,int* index, BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index])
	{
		pRoot = BuyBinTreeNode(array[*index]);

		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);

		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);

	}
	return pRoot;
}

BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}
// 二叉树的拷贝 
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* newpRoot = NULL;
	if (pRoot == NULL)
		return NULL;
	newpRoot = BuyBinTreeNode(pRoot->_data);
	newpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
	newpRoot->_pRight = CopyBinTree(pRoot->_pRight);
	return newpRoot;
}

// 二叉树的销毁 
void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

// 递归：前序遍历 
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 递归：中序遍历 
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// 递归：后序遍历 
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// 层序遍历 
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c", pCur->_data);
		
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pRight);
			QueuePop(&q);

	}
	QueueDestroy(&q);
	printf("\n");
}

void Swap(BTNode** pLeft, BTNode** pRight)
{
	BTNode* pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}

void MirrorNor(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
// 获取二叉树中节点个数 
int GetBinTreeSize(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;
}

// 获取二叉树中第K层节点个数 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K <= 0)
		return 0;
	if (1 == K)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) +
		GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

// 获取二叉树中叶子节点个数 
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
		
}

// 获取二叉树深度(高度) 
int GetBinTreeHeight(BTNode* pRoot)
{
	
	if (pRoot == NULL)
	{
		return 0;
	}
	int height = 1;
	while (pRoot->_pLeft || pRoot->_pRight)
	{
		height++;
		if (pRoot->_pLeft)
			pRoot = pRoot->_pLeft;
		if (pRoot->_pRight)
			pRoot = pRoot->_pRight;
	}
	return height;
}

// 检测值为x的元素是否在二叉树中，在返回该节点的地址，否则返回NULL 
BTNode* BinaryTreeFind(BTNode* pRoot, BTDataType x)
{
	BTNode* pRet = NULL;
	if (NULL == pRoot)
		return NULL;
	if (x == pRoot->_data)
		return pRoot;
	if (pRet = BinaryTreeFind(pRoot->_pLeft, x))
		return pRet;
	return BinaryTreeFind(pRoot->_pRight, x);

}


// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (root != NULL)
	{
		root = QueueFront(&q);
		QueuePop(&q);
		if (root != NULL)
		{
			QueuePush(&q, root->_pLeft);
			QueuePush(&q, root->_pRight);
		}
	}
	while (!QueueEmpty(&q))
	{
		root = QueueFront(&q);
		QueuePop(&q);
		if (root == NULL)
		{
			return -1;
		}
	}
	return 1;
}


