#include "sqstack.h"
#include <stdio.h>

int main(void)
{
   ElemType e;
    SqStack *s;
    printf("(1)��ʼ��ջs\n");
    InitStack(s);
    printf("(2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("(3)���ν�ջԪ��a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("(4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("(5)ջ����:%d\n",StackLength(s));
    printf("(6)��ջ����ջ��Ԫ��:");DispStack(s);
    printf("(7)��ջ����:");
    while (!StackEmpty(s))
    {
        Pop(s,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(8)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("(9)�ͷ�ջ\n");
    DestroyStack(s);
    return 0;
}


/*˳���
    SqList *sq;
    ElemType x[6]={5,8,7,2,4,9};
    CreateList(sq,x,6);
    DispList(sq);
    return 0;
    */
/**<����
    LinkList *L;
    InitLinkList(L);
    LinkListInsert(L,1,15);
    LinkListInsert(L,1,10);
    LinkListInsert(L,1,5);
    LinkListInsert(L,1,20);
    DispLinkList(L);
    DestroyLinkList(L);
    return 0;

 */
/*  ���������
    srand((unsigned)time(NULL));
    for(int i=10;i>0;i--)
    {
        printf("%d\n",rand());
    }*/
