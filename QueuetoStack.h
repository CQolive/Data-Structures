#pragma once

#include"Queue.h"
typedef int QueueStackType;
typedef struct Stack
{
	Queue q1;
	Queue q2;
}Stack;
void Stack_Init(Stack* s)
{
	assert(s);
	QueueInit(&(s->q1));
	QueueInit(&(s->q2));
}
void Stack_Push(Stack* s,QueueStackType date)
{
	assert(s);
	if (QueueEmpty(&(s->q1)))
	{
		QueuePush(&(s->q2), date);
	}
	//if (QueueEmpty(&(s->q2)))
	else
	{
		QueuePush(&(s->q1), date);
	}
}
void Stack_Pop(Stack* s)
{
	assert(s);
	if (QueueEmpty(&(s->q1)))//q1为空，
	{
		while (s->q2._front->_pNext)//出q2的数据到q1，最后一个出队列
		{
			QueuePush(&(s->q1), QueueFront(&(s->q2)));
			QueuePop(&(s->q2));
		}
			QueuePop(&(s->q2));
	}
	else
	{
		while (s->q1._front->_pNext)//出q1的数据到q2，最后一个出队列
		{
			QueuePush(&(s->q2), QueueFront(&(s->q1)));
			QueuePop(&(s->q1));
		}
			QueuePop(&(s->q1));
	}
}
QueueStackType Stack_Front(Stack* s)
{
	assert(s);
	if (QueueEmpty(&(s->q1)))
		return s->q2._back->_data;
	if (QueueEmpty(&(s->q2)))
		return s->q1._back->_data;
}
void Stack_Desyory(Stack* s)
{
	assert(s);
	QueueDestroy(&(s->q1));
	QueueDestroy(&(s->q2));
}

void TestQS()
{
	Stack s;
	Stack_Init(&s);
	Stack_Push(&s, 1);
	Stack_Push(&s, 2);
	Stack_Push(&s, 3);
	Stack_Push(&s, 4);
	Stack_Push(&s, 5);
	Stack_Pop(&s);
	Stack_Pop(&s);
	Stack_Pop(&s);
	printf("%d\n", Stack_Front(&s));
	Stack_Desyory(&s);
}


