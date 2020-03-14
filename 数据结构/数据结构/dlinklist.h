#ifndef DLINKLIST_H_INCLUDED
#define DLINKLIST_H_INCLUDED
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;
void CreateListF(DLinkList *&L,ElemType a[],int n);//ͷ�巨��˫����
void CreateListR(DLinkList *&L,ElemType a[],int n);//β�巨��˫����
void InitList(DLinkList *&L); //��ʼ��˫����
void DestroyList(DLinkList *&L); //����˫����
bool ListEmpty(DLinkList *L); //�ж������Ƿ�Ϊ��
int ListLength(DLinkList *L); //������ĳ���
void DispList(DLinkList *L); //�������
bool GetElem(DLinkList *L,int i,ElemType &e); //��ȡ�ڵ��ֵ
int LocateElem(DLinkList *L,ElemType e); //����һ���ڵ�
bool ListInsert(DLinkList *&L,int i,ElemType e) ;//����һ���ڵ�
bool ListDelete(DLinkList *&L,int i,ElemType &e); //ɾ��һ���ڵ�



#endif // DLINKLIST_H_INCLUDED
