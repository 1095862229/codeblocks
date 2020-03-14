#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkList;


void InitLinkList(LinkList *&L);//初始化单链表
void CreateLinkListF(LinkList *&L,ElemType a[],int n);//头插法建立单链表
void CreateLinkListR(LinkList *&L,ElemType a[],int n);//尾插法建立单链表
void DestroyLinkList(LinkList *&L);//销毁线性表
bool LinkListEmpty(LinkList *&L);//判定是否为空表
int LinkListLength(LinkList *L);//求线性表的长度
int LinkLocateElem(LinkList *L,ElemType e);//按元素值查找
bool LinkListInsert(LinkList *&L,int i,ElemType e);//插入数据元素
bool LinkListDelete(LinkList *&L,int i,ElemType e);//删除数据元素
void DispLinkList(LinkList *L);//输出单链表



#endif // LINKLIST_H_INCLUDED
