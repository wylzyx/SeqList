#include"SeqList.h"

void SeqListInit(SeqList* s, size_t capacity)
{
	// 在堆上分配顺序表的存储空间
	// 初始化容量、size 字段
	assert(s != NULL);

	s->arry = (SeqList*)malloc(sizeof(SeqList)* capacity);
	s->capacity = capacity;
	s->size = 0;
}

void SeqListDestory(SeqList* s)
{
	// 释放顺序表的存储空间
	// 额外的工作，把字段 reset 为初始值
	assert(s != NULL);
	assert(s->arry != NULL);
	
	free(s->arry);

	s->arry = NULL;
	s->size = 0;
	s->capacity = 0;
}

// O(n)
// static 修饰函数更改链接属性，从外部链接属性改变为内部链接属性
// 检查数据插入时，是否需要扩容，如果需要，则扩容
static void CheckCapacity(SeqList* s)
{
	if (s->size < s->capacity)
	{
		return;
	}

	// 需要扩容的情况
	// 申请新空间
	int newCapacity = 2 * s->capacity;
	SeqList* newArry = (SeqList*)malloc(sizeof(SeqList)* newCapacity);
	// copy 老数据到新空间
	for (int i = 0; i < s->size; ++i)
	{
		newArry[i] = s->arry[i];
	}

	// 释放老空间，把新空间绑定到顺序表结构体
	free(s->arry);
	s->arry = newArry;

	// 更新容量
	s->capacity = newCapacity;
}

// 时间复杂度 O(1)
void SeqListPushBack(SeqList* s, DataType x)
{
	assert(s != NULL);

	s->arry[s->size] = x;
	s->size++;
	
}

void SeqListPopBack(SeqList* s);

// O(n)
void SeqListPushFront(SeqList* s, DataType x)
{
	assert(s != NULL);
	// 数据的移动过程
	// i 空间
	for (int i = s->size; i >= 1; i--)
	{
		s->arry[i] = s->arry[i - 1];
	}
#if 0
	// i 数据
	for (int i = seqlist->size - 1; i >= 0; i--) 
	{ 
		s->arry[i + 1] = s->arry[i];
	}
#endif

	s->arry[0] = x;
	s->size++;
}

void SeqListPopFront(SeqList* s);

int SeqListFind(SeqList* s, DataType x);
void SeqListInsert(SeqList* s, size_t pos, DataType x);
void SeqListErase(SeqList* s, size_t pos);
void SeqListRemove(SeqList* s, DataType x);
void SeqListModify(SeqList* s, size_t pos, DataType x);
void SeqListPrint(SeqList* s);

void SeqListBubbleSort(SeqList* s);
int SeqListBinaryFind(SeqList* s, DataType x);
void SeqListRemoveAll(SeqList* s, DataType x);