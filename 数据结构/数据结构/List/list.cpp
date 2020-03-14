#include <stdio.h>
#include <malloc.h>
#include "list.h"

//用数组创建线性表
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//初始化线性表InitList(L)
void InitList(SqList *&L)   //引用型指针
{
    L=(SqList *)malloc(sizeof(SqList));
    //分配存放线性表的空间
    L->length=0;
}

//销毁线性表DestroyList(L)
void DestroyList(SqList *&L)
{
    free(L);
}

//判定是否为空表ListEmpty(L)
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}

//求线性表的长度ListLength(L)
int ListLength(SqList *L)
{
    return(L->length);
}

//输出线性表DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}
