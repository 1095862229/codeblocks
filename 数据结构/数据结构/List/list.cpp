#include <stdio.h>
#include <malloc.h>
#include "list.h"

//�����鴴�����Ա�
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//��ʼ�����Ա�InitList(L)
void InitList(SqList *&L)   //������ָ��
{
    L=(SqList *)malloc(sizeof(SqList));
    //���������Ա�Ŀռ�
    L->length=0;
}

//�������Ա�DestroyList(L)
void DestroyList(SqList *&L)
{
    free(L);
}

//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}

//�����Ա�ĳ���ListLength(L)
int ListLength(SqList *L)
{
    return(L->length);
}

//������Ա�DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}
