#include "list.h"

//void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
//void InitList(SqList *&L);//��ʼ�����Ա�InitList(L)
//void DestroyList(SqList *&L);//�������Ա�DestroyList(L)
//bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
//int ListLength(SqList *L);//�����Ա�ĳ���ListLength(L)
//void DispList(SqList *L);//������Ա�DispList(L)
//bool GetElem(SqList *L,int i,ElemType &e);//��ĳ������Ԫ��ֵGetElem(L,i,e)
//int LocateElem(SqList *L, ElemType e);//��Ԫ��ֵ����LocateElem(L,e)
//bool ListInsert(SqList *&L,int i,ElemType e);//��������Ԫ��ListInsert(L,i,e)
//bool ListDelete(SqList *&L,int i,ElemType &e);//ɾ������Ԫ��ListDelete(L,i,e)
int main()
{
    SqList *sq;
    ElemType x[6]= {5,8,7,2,4,9};
    CreateList(sq, x, 6);
    DispList(sq);
    return 0;
}
