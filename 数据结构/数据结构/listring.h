#ifndef LISTRING_H_INCLUDED
#define LISTRING_H_INCLUDED
typedef struct snode
{
    char data;
    struct snode *next;
} LiString;

void StrAssign(LiString *&s,char cstr[]);   //�ַ�������cstr������s
void StrCopy(LiString *&s,LiString *t); //��t���Ƹ���s
bool StrEqual(LiString *s,LiString *t); //�д����
int StrLength(LiString *s); //�󴮳�
LiString *Concat(LiString *s,LiString *t);  //������
LiString *SubStr(LiString *s,int i,int j);  //���Ӵ�
LiString *InsStr(LiString *s,int i,LiString *t) ;   //������
LiString *DelStr(LiString *s,int i,int j);  //��ɾȥ
LiString *RepStr(LiString *s,int i,int j,LiString *t);  //���滻
void DispStr(LiString *s);  //�����


#endif // LISTRING_H_INCLUDED
