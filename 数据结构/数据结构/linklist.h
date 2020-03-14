#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkList;


void InitLinkList(LinkList *&L);//��ʼ��������
void CreateLinkListF(LinkList *&L,ElemType a[],int n);//ͷ�巨����������
void CreateLinkListR(LinkList *&L,ElemType a[],int n);//β�巨����������
void DestroyLinkList(LinkList *&L);//�������Ա�
bool LinkListEmpty(LinkList *&L);//�ж��Ƿ�Ϊ�ձ�
int LinkListLength(LinkList *L);//�����Ա�ĳ���
int LinkLocateElem(LinkList *L,ElemType e);//��Ԫ��ֵ����
bool LinkListInsert(LinkList *&L,int i,ElemType e);//��������Ԫ��
bool LinkListDelete(LinkList *&L,int i,ElemType e);//ɾ������Ԫ��
void DispLinkList(LinkList *L);//���������



#endif // LINKLIST_H_INCLUDED
