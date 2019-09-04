#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int DataType;

typedef struct SeqList
{
	DataType* arry;
	size_t size;
	size_t capacity;
}SeqList;

//基本增删改查接口
void SeqListInit(SeqList* s, size_t capacity);
void SeqListDestory(SeqList* s);

void CheckCapacity(SeqList* s); 
void SeqListPushBack(SeqList* s, DataType x); 
void SeqListPopBack(SeqList* s); 
void SeqListPushFront(SeqList* s, DataType x); 
void SeqListPopFront(SeqList* s);

int SeqListFind(SeqList* s, DataType x); 
void SeqListInsert(SeqList* s, size_t pos, DataType x); 
void SeqListErase(SeqList* s, size_t pos); 
void SeqListRemove(SeqList* s, DataType x); 
void SeqListModify(SeqList* s, size_t pos, DataType x); 
void SeqListPrint(SeqList* s);

// 扩展面试题实现
void SeqListBubbleSort(SeqList* s);
int SeqListBinaryFind(SeqList* s, DataType x); 
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* s, DataType x);