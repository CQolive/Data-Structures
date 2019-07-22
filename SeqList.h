
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _size;
	int _capacity;

}SeqList, *PSeq;
//typedef struct SeqList SeqList; 
//typedef struct SeqList* PSeqList; 

//// 顺序表的初始化 
void SeqListInit(PSeq ps, int capacity)
{
	assert(ps);
	ps->_size = 0;
	ps->_capacity = capacity;
	ps->_array = (DataType*)malloc(ps->_capacity * sizeof(DataType));
	if (ps->_array == NULL)
	{
		return;
	} 
}
//// 顺序表的扩容 
void CheckCapacity(PSeq ps)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		ps->_capacity = ps->_capacity * 2;
		ps->_array = (DataType *)realloc(ps->_array, ps->_capacity * sizeof(DataType));
		if (ps->_array)
			printf("扩容成功");
	}
	return;
}
//// 在顺序表的尾部插入值为data的元素 
void SeqListPrint(PSeq ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
}
void SeqListPushBack(PSeq ps,DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//// 删除顺序表最后一个元素 
//void SeqListPopBack(PSeq ps);
void SeqListPopBack(PSeq ps)
{
	assert(ps);
	if (0 == ps->_size)
	{
		return;
	}
	ps->_size--;
}
//// 在顺序表的头部插入值为data的元素 
void SeqListPushFront(PSeq ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);

	for (int i = (ps->_size - 1); i >= 0; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}
//// 删除顺序表头部的元素 
void SeqListPopFront(PSeq ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		return;
	}
	for (int i = 1; i <= ps->_size - 1; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
//// 在顺序表pos位置插入值为data的元素 
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	assert(ps);
	
	CheckCapacity(ps);

	for (int i = ps->_size-1; i >= pos-1; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos - 1] = data;
	ps->_size++;
}
//// 删除顺序表中pos位置上的元素 
void SeqListErase(PSeq ps, int pos)
{
	assert(ps);
	if (ps->_size == 0) return;
	for (int i = pos - 1; i <= ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
//// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的下标，否则返回-1 
int SeqListFind(PSeq ps, DataType data)
{
	assert(ps);
	int count = ps->_size - 1;
	while (count-- >= 0)
	{
		if (data == ps->_array[count])
		{
			return count+1;
		}
	}
	return -1;
}
//// 检测顺序表是否为空，如果为空返回非0值，非空返回0 
int SeqListEmpty(PSeq ps)
{
	assert(ps);
	//if (ps->_size)
	//	return 0;
	//return 1;
	return ps->_size == 0 ? 1 : 0;
}
//// 返回顺序表中有效元素的个数 
int SeqListSize(PSeq ps)
{
	assert(ps);
	return ps->_size;
}
//// 返回顺序表的容量大小 
int SeqListCapacity(PSeq ps)
{
	assert(ps);
	return ps->_capacity;
}
//// 将顺序表中的元素清空 
void SeqListClear(PSeq ps)
{
	assert(ps);
	ps->_size = 0;
}
//// 删除顺序表中第一个值为data的元素 
void SeqListRemove(PSeq ps, DataType data)
{
	assert(ps);
	int num = SeqListFind(ps,data);
	SeqListErase(ps, num);
}

//// 销毁顺序表 
void SeqListDestroy(PSeq ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_size = 0;
	free(ps->_array);
}
