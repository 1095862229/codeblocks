#include "sort.h"
#include <stdio.h>


/*********************************************************
*����������ð������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/


void BubbleSort(RecType R[],int n)   //ð������
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
*������������������
*���������RecType R[]-����������,int s-Ԫ����С�±꣬Int t-Ԫ������±�
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/

void QuickSort(RecType R[],int s,int t)     //��������
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
*������������ѡ������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void SelectSort(RecType R[],int n)          //��ѡ������
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
*����������������
*���������RecType R[]-����������,int low-Ԫ����С�±꣬Int high-Ԫ������±�
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void sift(RecType R[],int low,int high)     //������
{
    int i=low,j=2*i;                        //R[j]��R[i]������
    RecType temp=R[i];
    while (j<=high)
    {
        if (j<high && R[j].key<R[j+1].key)  //���Һ��ӽϴ�,��jָ���Һ���
            {j++;}                                //��Ϊ2i+1
        if (temp.key<R[j].key)
        {
            R[i]=R[j];                          //��R[j]������˫�׽��λ����
            i=j;                                //�޸�i��jֵ,�Ա��������ɸѡ
            j=2*i;
        }
        else break;                             //ɸѡ����
    }
    R[i]=temp;                                  //��ɸѡ����ֵ��������λ��
}


/*********************************************************
*����������������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void HeapSort(RecType R[],int n)                //������
{
    int i;
    RecType temp;
    for (i=n/2; i>=1; i--) //ѭ��������ʼ��
        sift(R,i,n);
    for (i=n; i>=2; i--) //����n-1��ѭ��,���������
    {
        temp=R[1];       //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
        R[1]=R[i];
        R[i]=temp;
        sift(R,1,i-1);   //ɸѡR[1]���,�õ�i-1�����Ķ�
    }
}



/*********************************************************
*����������������
*���������RecType R[]-����������,int low-Ԫ����С�±꣬int mid-Ԫ���м��±�,Int high-Ԫ������±�
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void Merge(RecType R[],int low,int mid,int high)        //�鲢����
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

void MergePass(RecType R[],int length,int n)  //�������������һ�˹鲢
{
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)
        Merge(R,i,i+length-1,i+2*length-1);
    if(i+length-1<n)
        Merge(R,i,i+length-1,n-1);
}

void MergeSort(RecType R[],int n)   //�Ե����ϵĶ�·�鲢�㷨
{
    int length;
    for(length=1;length<n;length=2*length);
}

//��������


//8. ��������ĸ����������������������õ�����
void CreateLink(RadixRecType *&p,RecType R[],int n)   //���ú�巨��������
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

//8. ��������ĸ����������ͷŻ��������õ�����
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

//8. ʵ�ֻ�������:*pΪ��������������ָ��,����R�͹ؼ���λ��D�Ѿ���Ϊ���ų��������
void RadixSort(RadixRecType *&p)
{
    RadixRecType *head[Radix],*tail[Radix],*t; //��������ӵ���βָ��
    int i,j,k;
    unsigned int d1, d2=1;   //���ڷ������iλ���֣��������ע��
    for (i=1; i<=Digits; i++)                  //�ӵ�λ����λѭ��
    {
        //�����������iλ���֣���ͨ����d1=10^iȡ�࣬�õ����iλ����ͨ������d2=10^(i-1)�õ���iλ
        //���磬�����������1λ������λ�����ȶ�d1=10ȡ�࣬������d2=1
        //�����磬�����������2λ����ʮλ�����ȶ�d1=100ȡ�࣬������d2=10
        //ѭ��֮ǰ��d2�Ѿ���ʼ��Ϊ1������һ��ѭ��ĩ����10��
        //�������d2���õ�d1��ֵ
        d1=d2*10;
        for (j=0; j<Radix; j++)                 //��ʼ���������ס�βָ��
            head[j]=tail[j]=NULL;
        while (p!=NULL)                 //����ԭ������ÿ�����ѭ��
        {
            k=(p->data%d1)/d2;           //�������iλ����k
            if (head[k]==NULL)          //���з���
            {
                head[k]=p;
                tail[k]=p;
            }
            else
            {
                tail[k]->next=p;
                tail[k]=p;
            }
            p=p->next;                  //ȡ��һ���������Ԫ��
        }
        p=NULL;                         //������p���ռ����н��
        for (j=0; j<Radix; j++)             //����ÿһ������ѭ��
            if (head[j]!=NULL)          //�����ռ�
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
        t->next=NULL;                   //���һ������next����NULL
        //����������ڷ������iλ���ֵ�d2
        d2*=10;
    }
}

/*********************************************************
*����������ֱ�Ӳ�������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
    int i,j;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        j=i-1;            //����������������R[0..i-1]����R[i]�Ĳ���λ��
        while (j>=0 && tmp.key<R[j].key)
        {
            R[j+1]=R[j]; //���ؼ��ִ���R[i].key�ļ�¼����
            j--;
        }
        R[j+1]=tmp;      //��j+1������R[i]
    }
}

/*********************************************************
*�����������۰��������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void InsertSort1(RecType R[],int n) //��R[0..n-1]��������������۰��������
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
*����������ϣ������
*���������RecType R[]-����������,int n-Ԫ�ظ���
*�����������
*����ֵ��0-�ɹ� ����-ʧ��
*����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void ShellSort(RecType R[],int n)//ϣ������
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



























