#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SDataType;

typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node,*PNode;

typedef struct SList
{
	PNode _pHead;
}SList,*PSList;

//链表初始化
void SListInit(SList *s)
{
	assert(s);
	s->_pHead = NULL;
}
//创建一个节点
Node *BuyNode(SDataType data)
{
	Node* pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
//销毁节点
void SListDstoryNode(Node *node)
{
	assert(node);
	free(node);
	node = NULL;
}
// 在链表s最后一个节点后插入值为data的节点 
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	Node *pNewNode = BuyNode(data);
	Node *p = s->_pHead;
	if (s->_pHead == NULL)
	{
		s->_pHead = pNewNode;
	}
	else
	{
		while (p->_pNext)
		{
			p = p->_pNext;
		}
		p->_pNext = pNewNode;

	}
}

// 删除链表s最后一个节点 
void SListPopBack(SList* s)
{
	assert(s);
	Node *pCurNode = s->_pHead;
	Node *pPreNode = NULL;
	if (s->_pHead == NULL)
		return;
	if (pCurNode->_pNext == NULL)
	{
		pCurNode = NULL;
		return;
	}
	while (pCurNode->_pNext)
	{
		pPreNode = pCurNode;
		pCurNode = pCurNode->_pNext;
	}
	pPreNode->_pNext = NULL;
	SListDstoryNode(pCurNode);
}

//打印链表
void SListPrint(SList *s)
{
	assert(s);
	Node *p = s->_pHead;
	if (s->_pHead == NULL)
	{
		printf("NULL");
		return;
	}
	while (p)
	{
		printf("%d->", p->_data);
		p = p->_pNext;
	}
		printf("NULL\n");

}
//// 在链表s第一个节点前插入值为data的节点 
void SListPushBackFront(SList* s, SDataType data)
{
	assert(s);
	Node* pNewNode = BuyNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}
//// 删除链表s的第一个节点 
//void SListPopFront(SList* s);
void SListPopFront(SList* s)
{
	assert(s);
	Node* pPreNode = s->_pHead;
	if (s->_pHead == NULL)
		return;
	s->_pHead = s->_pHead->_pNext;
	SListDstoryNode(pPreNode);

}
//// 在链表的pos位置后插入值为data的节点 
void SListInsert(SList* s,PNode pos, SDataType data)
{
	assert(s);
	assert(pos);
	Node* pCurNode = s->_pHead;
	Node* pNewNode = BuyNode(data);
	if (pCurNode == NULL)
		return;//为空直接返回
	if (pos == pCurNode)
		SListPushBackFront(s, data);
	while (pCurNode != pos)
	{
		pCurNode = pCurNode->_pNext;
	}
	pNewNode->_pNext = pCurNode->_pNext;
	pCurNode->_pNext = pNewNode;
}
//// 删除链表s中pos位置的节点 
void SListErase(SList* s, PNode pos)
{
	assert(s);
	assert(pos);
	Node* pCurNode = s->_pHead;
	Node* pPreNode = NULL;
	if (pCurNode == NULL)
		return;
	if (pos == pCurNode)
	    SListPopFront(s);
	while (pos != pCurNode)
	{
		pPreNode = pCurNode;
		pCurNode = pCurNode->_pNext;
	}
	pPreNode->_pNext = pCurNode->_pNext;
	SListDstoryNode(pCurNode);

}

//// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
//PNode SListFind(SList* s, SDataType data);
Node* SListFind(SList* s, SDataType data)
{
	assert(s);
	Node* pCurNode = s->_pHead;
	if (pCurNode == NULL) return NULL;
	while (pCurNode->_pNext)
	{
		if (pCurNode->_data == data)
			return pCurNode;
		pCurNode = pCurNode->_pNext;
	}
	return NULL;
}
//// 获取链表中有效节点的个数 
size_t SListSize(SList* s)
{
	assert(s);
	int num = 0;
	while (s->_pHead->_pNext)
	{
		s->_pHead = s->_pHead->_pNext;
		num++;
	}
	return num;
}

//// 检测链表是否为空 
int SListEmpty(SList* s)
{
	assert(s);
	return s->_pHead == NULL;
}

//// 将链表中有效节点清空 
//void SListClear(SList* s);
//
//// 销毁链表 
void SListDestroy(SList* s)
{
	assert(s);
	Node* pCurNode = s->_pHead;
	Node* pPreNode = NULL;
	if (pCurNode == NULL)
		return;
	while (pCurNode)
	{
		pPreNode = pCurNode;
		pCurNode = pCurNode->_pNext;
		SListDstoryNode(pPreNode);
	}
	pCurNode = NULL;
}
