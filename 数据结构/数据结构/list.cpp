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


//求某个数据元素值GetElem(L,i,e)
bool GetElem(SqList *L,int i,ElemType &e)
{
  if(i<1 || i>L->length) return false;
  e=L->data[i-1];
  return true;
}

//按元素值查找LocateElem(L,e)
int LocateElem(SqList *L,ElemType e)
{
  int i=0;
  while(i<L->length && L->data[i]!=e) i++;
  if(i>=L->length) return 0;
  else return i+1;
}

//插入数据元素ListInsert(L,i,e)
bool ListInsert(SqList *&L,int i,ElemType e)
{
  int j;
  if (i<1 || i>L->length+1)
	return false;
  i--;
  for (j=L->length;j>i;j--)
	L->data[j]=L->data[j-1];
  L->data[i]=e;
  L->length++;
  return true;
}


//删除数据元素ListDelete(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e)
{
  int j;
  if(i<1 || i>L->length)
	return false;
  i--;
  e=L->data[i];
  for(j=i;j<L->length-1;j++)
	L->data[j]=L->data[j+1];
  L->length--;
  return true;
}
