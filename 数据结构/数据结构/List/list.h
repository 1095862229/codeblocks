#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;


void CreateList(SqList *&L, ElemType a[], int n);//用数组创建线性表
void InitList(SqList *&L);//初始化线性表InitList(L)
void DestroyList(SqList *&L);//销毁线性表DestroyList(L)
bool ListEmpty(SqList *L);//判定是否为空表ListEmpty(L)

#endif // LIST_H_INCLUDED
