#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;


void CreateList(SqList *&L, ElemType a[], int n);//用数组创建线性表
void InitList(SqList *&L);//初始化线性表
void DestroyList(SqList *&L);//销毁线性表
bool ListEmpty(SqList *L);//判定是否为空表
void DispList(SqList *L);//输出线性表
bool ListDelete(SqList *&L,int i,ElemType &e);//删除数据元素
bool ListInsert(SqList *&L,int i,ElemType e);//插入数据元素
int LocateElem(SqList *L,ElemType e);//按元素值查找
bool GetElem(SqList *L,int i,ElemType &e);//求某个数据元素值
#endif // LIST_H_INCLUDED
