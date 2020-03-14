#include "sort.h"
#include <stdio.h>


/*********************************************************
*功能描述：冒泡排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/


void BubbleSort(RecType R[],int n)   //冒泡排序
{
    int i,j,exchange;
    RecType tmp;
    for(i=0;i<n-1;i++)
    {
        exchange=0;
        for(j=n-1;j>i;j--)
        {
            if(R[j].key<R[j-1].key)
            {
                tmp=R[j];
                R[j]=R[j-1];
                R[j-1]=tmp;
            }
        }
    }
}

/*********************************************************
*功能描述：快速排序
*输入参数：RecType R[]-待排序数组,int s-元素最小下标，Int t-元素最大下标
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/

void QuickSort(RecType R[],int s,int t)     //快速排序
{
    int i=s,j=t;
    RecType tmp;
    if(s<t)
    {
        tmp=R[s];
        while(i!=j)
        {
            while(j>i && R[j].key>=tmp.key)
                j--;
            R[i]=R[j];
            while(i<j && R[i].key<=tmp.key)
                i++;
            R[j]=R[i];
        }
        R[i]=tmp;
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
    }
}


/*********************************************************
*功能描述：简单选择排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void SelectSort(RecType R[],int n)          //简单选择排序
{
    int i,j,k,l;
    RecType temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(R[j].key>R[k].key)
                k=j;
        if(k!=i)
        {
            temp=R[i];
            R[i]=R[k];
            R[k]=temp;
        }
    }
}



/*********************************************************
*功能描述：调整堆
*输入参数：RecType R[]-待排序数组,int low-元素最小下标，Int high-元素最大下标
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void sift(RecType R[],int low,int high)     //调整堆
{
    int i=low,j=2*i;                        //R[j]是R[i]的左孩子
    RecType temp=R[i];
    while (j<=high)
    {
        if (j<high && R[j].key<R[j+1].key)  //若右孩子较大,把j指向右孩子
            {j++;}                                //变为2i+1
        if (temp.key<R[j].key)
        {
            R[i]=R[j];                          //将R[j]调整到双亲结点位置上
            i=j;                                //修改i和j值,以便继续向下筛选
            j=2*i;
        }
        else break;                             //筛选结束
    }
    R[i]=temp;                                  //被筛选结点的值放入最终位置
}


/*********************************************************
*功能描述：堆排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void HeapSort(RecType R[],int n)                //堆排序
{
    int i;
    RecType temp;
    for (i=n/2; i>=1; i--) //循环建立初始堆
        sift(R,i,n);
    for (i=n; i>=2; i--) //进行n-1次循环,完成推排序
    {
        temp=R[1];       //将第一个元素同当前区间内R[1]对换
        R[1]=R[i];
        R[i]=temp;
        sift(R,1,i-1);   //筛选R[1]结点,得到i-1个结点的堆
    }
}



/*********************************************************
*功能描述：调整堆
*输入参数：RecType R[]-待排序数组,int low-元素最小下标，int mid-元素中间下标,Int high-元素最大下标
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void Merge(RecType R[],int low,int mid,int high)        //归并排序
{
    RecType *R1;
    int i=low,j=mid+1,k=0;
    R1=(RecType *)malloc((high-low+1)*sizeof(RecType));
    while(i<=mid && j<=high)
        if(R[i].key<=R[j].key)
        {
            R1[k]=R[i];
            i++;
            k++;
        }
        else
        {
            R1[k]=R[j];
            j++;
            k++;
        }
        while(i<=mid)
        {
            R1[k]=R[i];
            i++;
            k++;
        }
        while(j<high)
        {
            R1[k]=R[j];
            j++;
            k++;
        }
        for(k=0,i=low;i<=high;k++,i++)
            R[i]=R1[k];
}

void MergePass(RecType R[],int length,int n)  //对整个数序进行一趟归并
{
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)
        Merge(R,i,i+length-1,i+2*length-1);
    if(i+length-1<n)
        Merge(R,i,i+length-1,n-1);
}

void MergeSort(RecType R[],int n)   //自底向上的二路归并算法
{
    int length;
    for(length=1;length<n;length=2*length);
}

//基数排序


//8. 基数排序的辅助函数，创建基数排序用的链表
void CreateLink(RadixRecType *&p,RecType R[],int n)   //采用后插法产生链表
{
    int i;
    RadixRecType *s,*t;
    for (i=0; i<n; i++)
    {
        s=(RadixRecType *)malloc(sizeof(RadixRecType));
        s->data = R[i].key;
        if (i==0)
        {
            p=s;
            t=s;
        }
        else
        {
            t->next=s;
            t=s;
        }
    }
    t->next=NULL;
}

//8. 基数排序的辅助函数，释放基数排序用的链表
void DestoryLink(RadixRecType *&p)
{
    RadixRecType *q;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    return;
}

//8. 实现基数排序:*p为待排序序列链表指针,基数R和关键字位数D已经作为符号常量定义好
void RadixSort(RadixRecType *&p)
{
    RadixRecType *head[Radix],*tail[Radix],*t; //定义各链队的首尾指针
    int i,j,k;
    unsigned int d1, d2=1;   //用于分离出第i位数字，见下面的注释
    for (i=1; i<=Digits; i++)                  //从低位到高位循环
    {
        //分离出倒数第i位数字，先通过对d1=10^i取余，得到其后i位，再通过整除d2=10^(i-1)得到第i位
        //例如，分离出倒数第1位，即个位数，先对d1=10取余，再整除d2=1
        //再例如，分离出倒数第2位，即十位数，先对d1=100取余，再整除d2=10
        //循环之前，d2已经初始化为1，在这一层循环末增加10倍
        //下面根据d2，得到d1的值
        d1=d2*10;
        for (j=0; j<Radix; j++)                 //初始化各链队首、尾指针
            head[j]=tail[j]=NULL;
        while (p!=NULL)                 //对于原链表中每个结点循环
        {
            k=(p->data%d1)/d2;           //分离出第i位数字k
            if (head[k]==NULL)          //进行分配
            {
                head[k]=p;
                tail[k]=p;
            }
            else
            {
                tail[k]->next=p;
                tail[k]=p;
            }
            p=p->next;                  //取下一个待排序的元素
        }
        p=NULL;                         //重新用p来收集所有结点
        for (j=0; j<Radix; j++)             //对于每一个链队循环
            if (head[j]!=NULL)          //进行收集
            {
                if (p==NULL)
                {
                    p=head[j];
                    t=tail[j];
                }
                else
                {
                    t->next=head[j];
                    t=tail[j];
                }
            }
        t->next=NULL;                   //最后一个结点的next域置NULL
        //下面更新用于分离出第i位数字的d2
        d2*=10;
    }
}

/*********************************************************
*功能描述：直接插入排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void InsertSort(RecType R[],int n) //对R[0..n-1]按递增有序进行直接插入排序
{
    int i,j;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        j=i-1;            //从右向左在有序区R[0..i-1]中找R[i]的插入位置
        while (j>=0 && tmp.key<R[j].key)
        {
            R[j+1]=R[j]; //将关键字大于R[i].key的记录后移
            j--;
        }
        R[j+1]=tmp;      //在j+1处插入R[i]
    }
}

/*********************************************************
*功能描述：折半插入排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void InsertSort1(RecType R[],int n) //对R[0..n-1]按递增有序进行折半插入排序
{
    int i,j,low,high,mid;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        low=0;
        high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (tmp.key<R[mid].key)
                high=mid-1;
            else
                low=mid+1;
        }
        for (j=i-1; j>=high+1; j--)
            {R[j+1]=R[j];}
        R[high+1]=tmp;
    }
}



/*********************************************************
*功能描述：希尔排序
*输入参数：RecType R[]-待排序数组,int n-元素个数
*输出参数：无
*返回值：0-成功 其他-失败
*其它说明：消息字段之间用分号(;)分隔
************************************************************/
void ShellSort(RecType R[],int n)//希尔排序
{
    int i,j,gap,k;
    RecType tmp;
    gap=n/2;
    while(gap>0)
    {
        for(i=gap;i<n;i++)
        {
            tmp=R[i];
            j=i-gap;
            while(j>=0 && tmp.key<R[j].key)
            {
                R[j+gap]=R[j];
                j=j-gap;
            }
            R[j+gap]=tmp;
            j=j-gap;
        }
        gap=gap/2;
    }
}



























