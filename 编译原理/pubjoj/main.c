#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int i,h;
	scanf("%d",&i);
	int list[i];
	int list2[i];
	for(int j=0;j<i;j++)
	{
		scanf("%d",&list[j]);
		list2[j]=1;
	}
//	for(int j=0;j<i;j++)
//	{
//		printf("%d",list[j]);
//	}
//	for(int j=0;j<i;j++)
//	{
//		printf("%d",list2[j]);
//	}
	for(int j=0;j<i;j++)
		for(int k=0;k<i;k++)
		{
			if(j==k)
				continue;
			if(list[j]==list[k]);
			{
				list2[j]=0; printf("%d %d\n",j,k);
			}
		}
	for(int j=0;j<i;j++)
	{
		printf("%d",list2[j]);
	}
	for(int j=0;j<i;j++)
		if(list2[j]==1)
			printf("%d",list[j]);
	return 0;
}
