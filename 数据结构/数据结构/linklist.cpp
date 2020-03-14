#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

//头插法建立单链表
void CreateLinkListF(LinkList *&L,ElemType a[],int n)
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    for(i=0;i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}


//为插法建立单链表
void CreateLinkListR(LinkList *&L,ElemType a[],int n)
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    r=L;
    for(i=0;i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}


//初始化线性表
void InitLinkList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
}

//销毁线性表
void DestroyLinkList(LinkList *&L)
{
    LinkList *pre=L,*p=L->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}

//判定是否为空表
bool LinkListEmpty(LinkList *&L)
{
    return(L->next==NULL);
}

//求线性表的长度
int LinkListLength(LinkList *L)
{
    LinkList *p=L;
    int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

//求线性表某个数据元素值
bool GetLinkElem(LinkList *&L,int i,ElemType &e)
{
    int j=0;
    LinkList *p=L;
    while(j<i && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }


}

//按元素值查找
int LinkLocateElem(LinkList *L,ElemType e)
{
    int i=1;
    LinkList *p=L->next;
    while(p!=NULL && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return false;
    else
        return(i);
}



//插入数据元素LinkListInsert(&L,i,e)
bool LinkListInsert(LinkList *&L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*s;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}


//删除数据元素
bool LinkListDelete(LinkList *&L,int i,ElemType e)
{
    int j=0;
    LinkList *p=L,*q;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        q=p->next;
        p=p->next->next;
        free(q);
        return true;
    }
}

//输出单链表
void DispLinkList(LinkList *L)
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}












