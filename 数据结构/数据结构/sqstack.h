#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;                //ջָ��
} SqStack;                  //˳��ջ���Ͷ���

void InitStack(SqStack *&s);    //��ʼ��ջ
void DestroyStack(SqStack *&s);  //����ջ
bool StackEmpty(SqStack *s);     //ջ�Ƿ�Ϊ��
int StackLength(SqStack *s);  //����ջ��Ԫ�ظ�������ջ����
bool Push(SqStack *&s,ElemType e); //��ջ
bool Pop(SqStack *&s,ElemType &e); //��ջ
bool GetTop(SqStack *s,ElemType &e); //ȡջ������Ԫ��
void DispStack(SqStack *s);  //���ջ

#endif // SQSTACK_H_INCLUDED
