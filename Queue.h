#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->_back = q->_front = NULL;

}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
QNode* BuyQNode(QDataType x)
{
	QNode* newNode = (QNode *)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		assert(0);
		return;
	}
	newNode->_data = x;
	newNode->_pNext = NULL;
	return newNode;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = BuyQNode(data);
	if (QueueEmpty(q))
	{
		q->_front = newNode;
		q->_back = q->_front;
	}
	{
		q->_back->_pNext = newNode;
		q->_back = q->_back->_pNext;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return;
	}
	QNode* tmp = q->_front;
	q->_front = q->_front->_pNext;
	free(tmp);
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return NULL;
	}
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return NULL;
	}
	return q->_back->_data;

}
int QueueSize(Queue* q)
{
	assert(q);
	QNode* CurNode = q->_front;
	int count = 0;
	if (QueueEmpty(q))
		return count;
	while (CurNode != NULL)
	{
		CurNode = CurNode->_pNext;
		count++;
	}
	return count;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
		return;
	QNode* CurNode = q->_front;
	QNode* tmp = NULL;
	while (CurNode)
	{
		tmp = CurNode;
		CurNode = CurNode->_pNext;
		free(tmp);
	}
	CurNode = NULL;
}
void QueuePrint(Queue* q)
{
	assert(q);
	QNode* CurNode = q->_front;
	while (CurNode)
	{
		printf("%d->", CurNode->_data);
		CurNode = CurNode->_pNext;
	}
	printf("\n");
}

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	QueuePrint(&q);
	printf("the size of queue: %d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);
	printf("the size of queue: %d\n", QueueSize(&q));
	printf("The number of front: %d\n", QueueFront(&q));
	printf("The number of back: %d\n", QueueBack(&q));
	QueueDestroy(&q);

}
