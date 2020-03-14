#include "dlinklist.h"
#include <stdio.h>
#include <malloc.h>


//ͷ�巨����˫����
void CreateListF(DLinkList *&L,ElemType a[],int n)
{
    DLinkList *s;
    int i;
    L=(DLinkList *)malloc(sizeof(DLinkList));
    L->prior=L->next=NULL;
    for(i=0;i<n;i++)
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL) L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
}

//β�巨����˫����
void CreateListR(DLinkList *&L,ElemType a[],int n)
{
    DLinkList *s,*r;
    int i;
    L=(DLinkList *)malloc(sizeof(DLinkList));
    L->prior=L->next=NULL;
    r=L;                     //rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
    for(i=0;i<n;i++)
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}


//��ʼ��˫����
void InitList(DLinkList *&L)
{
    L=(DLinkList *)malloc(sizeof(DLinkList));
    L->prior=L->next=NULL;
}

//�ͷ�˫����
void DestroyList(DLinkList *&L)
{
    DLinkList *p=L,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

//����һ���ڵ�
bool ListInsert(DLinkList *&L,int i,ElemType e)
{
    int j=0;
    DLinkList *p=L,*s;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL) p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
}


//ɾ�����
bool ListDelete(DLinkList *&L,int i,ElemType &e)
{
    int j=0;
    DLinkList *p=L,*q=NULL;
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
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        if(p->next!=NULL) p->next->prior=p;
        free(q);
        return true;
    }
}

//�ж��Ƿ�Ϊ�ձ�
bool ListEmpty(DLinkList *L)
{
    return (L->next==NULL);
}

//����˫������
int ListLength(DLinkList *L)
{
    DLinkList *p=L;
    int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}

//�������
void DispList(DLinkList *L)
{
    DLinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

//��ȡ��λ������
bool GetElem(DLinkList *L,int i,ElemType &e)
{
    int j=0;
    DLinkList *p=L;
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

//����ֵΪe��λ��
int LocateElem(DLinkList *L,ElemType e)
{
    int n=1;
    DLinkList *p=L->next;
    while(p!=NULL && p->data!=e)
    {
        n++;
        p=p->next;
    }
    if(p==NULL)
        return(0);
    else
        return(n);
}












