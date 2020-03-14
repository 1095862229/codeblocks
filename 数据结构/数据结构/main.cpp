#include "sqstack.h"
#include <stdio.h>

int main(void)
{
   ElemType e;
    SqStack *s;
    printf("(1)初始化栈s\n");
    InitStack(s);
    printf("(2)栈为%s\n",(StackEmpty(s)?"空":"非空"));
    printf("(3)依次进栈元素a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("(4)栈为%s\n",(StackEmpty(s)?"空":"非空"));
    printf("(5)栈长度:%d\n",StackLength(s));
    printf("(6)从栈顶到栈底元素:");DispStack(s);
    printf("(7)出栈序列:");
    while (!StackEmpty(s))
    {
        Pop(s,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(8)栈为%s\n",(StackEmpty(s)?"空":"非空"));
    printf("(9)释放栈\n");
    DestroyStack(s);
    return 0;
}


/*顺序表
    SqList *sq;
    ElemType x[6]={5,8,7,2,4,9};
    CreateList(sq,x,6);
    DispList(sq);
    return 0;
    */
/**<链表
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
/*  产生随机数
    srand((unsigned)time(NULL));
    for(int i=10;i>0;i--)
    {
        printf("%d\n",rand());
    }*/
