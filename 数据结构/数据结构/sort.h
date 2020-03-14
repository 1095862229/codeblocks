#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <malloc.h>

extern  int cmp1,cmp2,cmp3,cmp4,cmp5,cmp6;
extern  int move1,move2,move3,move4,move5,move6;
#define MaxSize 10000
//下面的符号常量和结构体针对基数排序
#define Radix 10           //基数的取值
#define Digits 10          //关键字位数

typedef int KeyType;    //定义关键字类型
typedef char InfoType[10];
typedef struct          //记录类型
{
    KeyType key;        //关键字项
    InfoType data;      //其他数据项,类型为InfoType
} RecType;              //排序的记录类型定义

typedef struct node
{
    KeyType data;      //记录的关键字，同算法讲解中有差别
    struct node *next;
} RadixRecType;


void BubbleSort(RecType R[],int n);//冒泡排序
void QuickSort(RecType R[],int s,int t);//快速排序
void SelectSort(RecType R[],int n);//简单选择排序
void HeapSort(RecType Rp[],int n);//堆排序
void sift(RecType R[],int low,int high);//调整堆
void Merge(RecType R[],int low,int mid,int high);//两路归并
void MergePass(RecType R[],int length,int n);  //对整个数序进行一趟归并
void MergeSort(RecType R[],int n);   //自底向上的二路归并算法

void CreateLink(RadixRecType *&p,RecType R[],int n);  //采用后插法产生链表
void DestoryLink(RadixRecType *&p);//8. 基数排序的辅助函数，释放基数排序用的链表
void RadixSort(RadixRecType *&p);//8. 实现基数排序:*p为待排序序列链表指针,基数R和关键字位数D已经作为符号常量定义好

void InsertSort1(RecType R[],int n); //对R[0..n-1]按递增有序进行折半插入排序
void InsertSort(RecType R[],int n); //对R[0..n-1]按递增有序进行直接插入排序
void ShellSort(RecType R[],int n);//希尔排序

#endif // SORT_H_INCLUDED
