#include"SeqList.h"

void SeqListInit(SeqList* s, size_t capacity)
{
	// �ڶ��Ϸ���˳���Ĵ洢�ռ�
	// ��ʼ��������size �ֶ�
	assert(s != NULL);

	s->arry = (SeqList*)malloc(sizeof(SeqList)* capacity);
	s->capacity = capacity;
	s->size = 0;
}

void SeqListDestory(SeqList* s)
{
	// �ͷ�˳���Ĵ洢�ռ�
	// ����Ĺ��������ֶ� reset Ϊ��ʼֵ
	assert(s != NULL);
	assert(s->arry != NULL);
	
	free(s->arry);

	s->arry = NULL;
	s->size = 0;
	s->capacity = 0;
}

// O(n)
// static ���κ��������������ԣ����ⲿ�������Ըı�Ϊ�ڲ���������
// ������ݲ���ʱ���Ƿ���Ҫ���ݣ������Ҫ��������
static void CheckCapacity(SeqList* s)
{
	if (s->size < s->capacity)
	{
		return;
	}

	// ��Ҫ���ݵ����
	// �����¿ռ�
	int newCapacity = 2 * s->capacity;
	SeqList* newArry = (SeqList*)malloc(sizeof(SeqList)* newCapacity);
	// copy �����ݵ��¿ռ�
	for (int i = 0; i < s->size; ++i)
	{
		newArry[i] = s->arry[i];
	}

	// �ͷ��Ͽռ䣬���¿ռ�󶨵�˳���ṹ��
	free(s->arry);
	s->arry = newArry;

	// ��������
	s->capacity = newCapacity;
}

// ʱ�临�Ӷ� O(1)
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
	// ���ݵ��ƶ�����
	// i �ռ�
	for (int i = s->size; i >= 1; i--)
	{
		s->arry[i] = s->arry[i - 1];
	}
#if 0
	// i ����
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