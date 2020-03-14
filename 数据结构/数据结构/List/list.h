#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;


void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
void InitList(SqList *&L);//��ʼ�����Ա�InitList(L)
void DestroyList(SqList *&L);//�������Ա�DestroyList(L)
bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)

#endif // LIST_H_INCLUDED
