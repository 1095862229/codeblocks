#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <malloc.h>

extern  int cmp1,cmp2,cmp3,cmp4,cmp5,cmp6;
extern  int move1,move2,move3,move4,move5,move6;
#define MaxSize 10000
//����ķ��ų����ͽṹ����Ի�������
#define Radix 10           //������ȡֵ
#define Digits 10          //�ؼ���λ��

typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

typedef struct node
{
    KeyType data;      //��¼�Ĺؼ��֣�ͬ�㷨�������в��
    struct node *next;
} RadixRecType;


void BubbleSort(RecType R[],int n);//ð������
void QuickSort(RecType R[],int s,int t);//��������
void SelectSort(RecType R[],int n);//��ѡ������
void HeapSort(RecType Rp[],int n);//������
void sift(RecType R[],int low,int high);//������
void Merge(RecType R[],int low,int mid,int high);//��·�鲢
void MergePass(RecType R[],int length,int n);  //�������������һ�˹鲢
void MergeSort(RecType R[],int n);   //�Ե����ϵĶ�·�鲢�㷨

void CreateLink(RadixRecType *&p,RecType R[],int n);  //���ú�巨��������
void DestoryLink(RadixRecType *&p);//8. ��������ĸ����������ͷŻ��������õ�����
void RadixSort(RadixRecType *&p);//8. ʵ�ֻ�������:*pΪ��������������ָ��,����R�͹ؼ���λ��D�Ѿ���Ϊ���ų��������

void InsertSort1(RecType R[],int n); //��R[0..n-1]��������������۰��������
void InsertSort(RecType R[],int n); //��R[0..n-1]�������������ֱ�Ӳ�������
void ShellSort(RecType R[],int n);//ϣ������

#endif // SORT_H_INCLUDED
