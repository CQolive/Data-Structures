#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _size;
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_size = 0;
	ps->_capacity = 10;
	ps->_array = (SDataType *)malloc(ps->_capacity * sizeof(SDataType));
	if (ps->_array == NULL)
	{
		assert(0);
		return;
	}

}
void StackCheck(Stack* ps)
{
	assert(ps);
	SDataType* tmp = NULL;
		ps->_capacity += 10;
		ps->_array = (SDataType *)realloc(ps->_array,ps->_capacity * sizeof(SDataType));
		if (ps->_array == NULL)
		{
			assert(0);
			return;
		}
		//free(ps->_array);
		//ps->_array = tmp;
		//free(tmp);
}
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		ps->_capacity += 10;
		ps->_array = (SDataType *)realloc(ps->_array, ps->_capacity * sizeof(SDataType));
		if (ps->_array == NULL)
		{
			assert(0);
			return;
		}
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		return;
	}
	ps->_size--;
}
SDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		return NULL;
	}
	return ps->_array[ps->_size - 1];

}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;
}
void StackDestroy(Stack* ps)
{
    assert(ps);
	ps->_capacity = 0;
	ps->_size = 0;
	free(ps->_array);
}
void StackPrint(Stack* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
		printf("%d->", ps->_array[i]);
	
void Test()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackPush(&ps, 1);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 2);
	StackPush(&ps, 2);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPrint(&ps);
    
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPrint(&ps);
	
	printf("the number og top : %d", StackTop(&ps));

	StackDestroy(&ps);

}
