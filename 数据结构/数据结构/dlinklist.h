#ifndef DLINKLIST_H_INCLUDED
#define DLINKLIST_H_INCLUDED
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;
void CreateListF(DLinkList *&L,ElemType a[],int n);//头插法建双链表
void CreateListR(DLinkList *&L,ElemType a[],int n);//尾插法建双链表
void InitList(DLinkList *&L); //初始化双链表
void DestroyList(DLinkList *&L); //销毁双链表
bool ListEmpty(DLinkList *L); //判断链表是否为空
int ListLength(DLinkList *L); //求链表的长度
void DispList(DLinkList *L); //输出链表
bool GetElem(DLinkList *L,int i,ElemType &e); //获取节点的值
int LocateElem(DLinkList *L,ElemType e); //查找一个节点
bool ListInsert(DLinkList *&L,int i,ElemType e) ;//插入一个节点
bool ListDelete(DLinkList *&L,int i,ElemType &e); //删除一个节点



#endif // DLINKLIST_H_INCLUDED
