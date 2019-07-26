#pragma once
#include "assert.h"
#include <stdio.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
}Heap;

void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下调整
void  AdjustDown(Heap* hp,int size,int root)
{
	assert(hp);
	int child = root * 2 + 1;
	while (child < size)
	{
		if (((child + 1) < size) && (hp->_array[child + 1] < hp->_array[child]))
		{
			child = child + 1;
		}
		if ((hp->_array[root]) > (hp->_array[child]))
		{
			Swap(&(hp->_array[root]), &(hp->_array[child]));
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			return;
		}
		
	}
}
//向上调整
void AdjustUp(Heap* hp, int size, int child)
{
	int parent = (child-1) / 2;
	while (parent >= 0 && child != 0)
	{
		if (hp->_array[parent] > hp->_array[child])
		{
			Swap(&(hp->_array[parent]), &(hp->_array[child]));
		}
			child = parent;
			parent = (child-1) / 2;
	}
}
// 用数组初始化堆 
void InitHeap(Heap* hp, HPDataType* array, int size)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL)
	{
		assert(hp->_array);
		return;
	}
	for (int i = 0; i < size; i++)
	{
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;
	int root = size / 2;
	for(;root >=0;--root)
	AdjustDown(hp,size,root);
}

// 初始化一个空堆 
void InitEmptyHeap(Heap* hp, int capacity)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*capacity);
	if (hp->_array == NULL)
	{
		assert(hp->_array);
		return;
	}
	hp->_size = 0;
	hp->_capacity = capacity;
}

// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, HPDataType data)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity += hp->_capacity;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		if (hp->_array == NULL)
		{
			assert(0);
			return;
		}
	}
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUp(hp,hp->_size,hp->_size - 1);
}

// 删除堆顶元素 
void EraseHeap(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return;
	}
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp,hp->_size,0);
}

// 获取堆中有效元素个数 
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 检测堆是否为空堆 
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}

// 获取堆顶元素 
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return NULL;
	}
	return hp->_array[hp->_size - 1];
}
// 销毁堆 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_array = NULL;
		hp->_size = 0;
		hp->_capacity = 0;
	}
}
void HeadTest()
{
	Heap hp;
	int a[] = {6,5,4,3,2,1};
	InitHeap(&hp, a, sizeof(a) / sizeof(a[0]));
	InsertHeap(&hp, 0);
}
