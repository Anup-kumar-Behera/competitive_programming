
#include <stdio.h>

/* function to show bytes in memory, from location start to start+n*/
int sum(int a, int b){
	return a + b;
}
int sum(int a, int b, int c){
	return a+b+c;
}
/*Main function to call above function for 0x01234567*/
int main()
{
	int k = sum(10, 20);
	int l = sum(1, 2, 3);
	
	printf("%d %d", k, l);

	return 0;
}

