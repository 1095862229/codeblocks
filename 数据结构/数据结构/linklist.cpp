#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

//ͷ�巨����������
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


//Ϊ�巨����������
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


//��ʼ�����Ա�
void InitLinkList(LinkList *&L)
{
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
}

//�������Ա�
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

//�ж��Ƿ�Ϊ�ձ�
bool LinkListEmpty(LinkList *&L)
{
    return(L->next==NULL);
}

//�����Ա�ĳ���
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

//�����Ա�ĳ������Ԫ��ֵ
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

//��Ԫ��ֵ����
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



//��������Ԫ��LinkListInsert(&L,i,e)
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


//ɾ������Ԫ��
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

//���������
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












