#include <stdio.h>
#include <sys/timeb.h>
#include <sys/type.h>
#include <time.h>
int main( void )
{
struct timeb timebuffer,timebuffer2;
time_t time1,time2;
unsigned short millitm1,millitm2;
ftime( &timebuffer1 );
time1 = timebuffer1.time;
millitm1 = timebuffer1.millitm;
//��ǰʱ�����ֵ
printf( "Seconds since midnight, January 1, 1970 (UTC): %Id\n",time1);
//��ǰʱ��ĺ���ֵ
printf( "Milliseconds: %d\n", millitm1);
//���������֡���
//�����������ʱ��Ĳ�ֵ�������´���
ftime( &timebuffer2 );
time2 = timebuffer2.time;
millitm2 = timebuffer2.millitm;
printf("difftime is%ld\n", (time2-time1)*1000+millitm2-millitm1);
}
