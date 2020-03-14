#ifndef LISTRING_H_INCLUDED
#define LISTRING_H_INCLUDED
typedef struct snode
{
    char data;
    struct snode *next;
} LiString;

void StrAssign(LiString *&s,char cstr[]);   //字符串常量cstr赋给串s
void StrCopy(LiString *&s,LiString *t); //串t复制给串s
bool StrEqual(LiString *s,LiString *t); //判串相等
int StrLength(LiString *s); //求串长
LiString *Concat(LiString *s,LiString *t);  //串连接
LiString *SubStr(LiString *s,int i,int j);  //求子串
LiString *InsStr(LiString *s,int i,LiString *t) ;   //串插入
LiString *DelStr(LiString *s,int i,int j);  //串删去
LiString *RepStr(LiString *s,int i,int j,LiString *t);  //串替换
void DispStr(LiString *s);  //输出串


#endif // LISTRING_H_INCLUDED
