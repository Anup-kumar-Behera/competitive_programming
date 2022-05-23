#include<stdio.h>

struct a{
	int name[20];
	int roll;
};
main()
{
	struct a p2;
//	struct a p1{'Anup',118152};
	scanf("%s %d",p2.name,&p2.roll);
	
//	printf("%s %d	\n",p1.name,p1.roll);
	printf("%s %d 	\n",p2.name,p2.roll);
}
