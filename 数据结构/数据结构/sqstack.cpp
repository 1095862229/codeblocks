#include  "sqstack.h"
#include <stdio.h>
#include <malloc.h>

void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

int StackLength(SqStack *s)  //返回栈中元素个数——栈长度
{
    return(s->top+1);
}

bool StackEmpty(SqStack *s)
{
    return(s->top==-1);
}

bool Push(SqStack *&s,ElemType e)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s,ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}

void DispStack(SqStack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
        printf("%c",s->data[i]);
    printf("\n");
}



































