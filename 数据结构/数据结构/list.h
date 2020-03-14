#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;


void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
void InitList(SqList *&L);//��ʼ�����Ա�
void DestroyList(SqList *&L);//�������Ա�
bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�
void DispList(SqList *L);//������Ա�
bool ListDelete(SqList *&L,int i,ElemType &e);//ɾ������Ԫ��
bool ListInsert(SqList *&L,int i,ElemType e);//��������Ԫ��
int LocateElem(SqList *L,ElemType e);//��Ԫ��ֵ����
bool GetElem(SqList *L,int i,ElemType &e);//��ĳ������Ԫ��ֵ
#endif // LIST_H_INCLUDED
