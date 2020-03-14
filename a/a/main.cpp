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
//当前时间的秒值
printf( "Seconds since midnight, January 1, 1970 (UTC): %Id\n",time1);
//当前时间的毫秒值
printf( "Milliseconds: %d\n", millitm1);
//主函数部分……
//如果想获得两个时间的差值，见如下代码
ftime( &timebuffer2 );
time2 = timebuffer2.time;
millitm2 = timebuffer2.millitm;
printf("difftime is%ld\n", (time2-time1)*1000+millitm2-millitm1);
}
