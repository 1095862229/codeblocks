#include<stdio.h>
#include<string.h>

char prog[100],token[8],ch;
char *rwtab[6]={"begin","if","then","while","do","end"};
int syn,p,m,n,sum;

void E();            //E->TE1;
void E1();           //E1->+TE1|-TE1|¦Å
void T();            //T->FT1
void T1();            //T1->*FT1 |/FT1|¦Å
void F();            //F->(E) | i

error();
void scaner();

int main()
{
    int i = 0;
    for( ;i<3; i++)
    {
        p=0;
        printf("\nplease input a string (end with '#'): \n");

       do
        {
            scanf("%c",&ch);
            prog[p++]=ch;
        }while(ch!='#');
        if(i<2)
            printf("success!\r\n");
        else
            printf("error!\r\n");
    }


    p=0;
    scaner();
    E();

}


void E()
{
    T();
    E1();
}

void E1()
{
    if((syn==13)||(syn==14))
    {
        scaner();
        T();
        E1();

    }
    else
    {
        if(syn!=28 && syn!=0)
        error();
    }
}

void T()
{
    F();
    T1();
}
void T1()
{
    if((syn==15)||(syn==16))
    {
       scaner();
       F();
       T1();
    }
    else
    {
        if(syn!=28 && syn!=0 && syn!=13)
        error();
    }

}
void F()
{
    if(syn==27)
    {
        scaner();
        E();
        if(syn==28)
        {
            scaner();
            E();
            if(syn==0)
                printf("\nTrue!\n");
        }
        else
        error();
    }
    else if(syn==11||syn==10)
        scaner();
}

error()
{
    printf("\n Syn Error!\n");
}

void scaner()
{
    sum=0;

    for(m=0;m<8;m++)
        token[m++]=NULL;

    m=0;
    ch=prog[p++];

    while(ch==' ')
        ch=prog[p++];

    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))
    {
        while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')))
        {
            token[m++]=ch;
            ch=prog[p++];
        }
        p--;
        syn=10;
        token[m++]='\0';
        for(n=0;n<6;n++)
        if(strcmp(token,rwtab[n])==0)
        {
            syn=n+1;
            break;
        }
    }
    else if((ch>='0')&&(ch<='9'))
    {
        while((ch>='0')&&(ch<='9'))
        {
            sum=sum*10+ch-'0';
            ch=prog[p++];
        }
        p--;
        syn=11;
    }
    else
    switch(ch)
    {
        case '<':
            m=0;
            ch=prog[p++];
            if(ch=='>')
            {
                syn=21;
            }
            else if(ch=='=')
            {
                syn=22;
            }
            else
            {
                syn=20;
                p--;
            }
        break;

        case '>':
            m=0;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=24;
            }
            else
            {
                syn=23;
                p--;
            }
        break;

        case ':':
            m=0;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=18;
            }
            else
            {
                syn=17;
                p--;
            }
            break;

        case '+':
            syn=13;
        break;

        case '-':
            syn=14;
        break;

        case '*':
            syn=15;
        break;

        case '/':
            syn=16;
        break;

        case '(':
            syn=27;
        break;

        case ')':
            syn=28;
        break;

        case '=':
            syn=25;
        break;

        case ';':
            syn=26;
        break;

        case '#':
            syn=0;
        break;

        default:
            syn=-1;
        break;
    }
}
