#include<iostream>
using namespace std;

int checkFive(int n){
	int t = n, m = n;
	int c = 0, k = 0;
	while(n > 0){
		int temp = n % 10;
		c += 1;
		if(c == 1)
			k = 5;
		else if(c == 2)
			k = 50;
		else if(c == 3)
			k = 500;
		else if(c == 4)
			k == 5000;
		else if(c == 5)
			k = 50000;
		if (temp % 5 == 0 && temp % 10 == 0)
		{
			m = m + k;
		}
		n /= 10;
	}
	return m;
}

int main(){
	
	int n ;
	scanf("%d",&n);
	
	int k = checkFive(n);
	printf("\nThe entered number is: %d ",n);
	printf("\nThe modified number is: %d\n",k);
	
	return 0;
}
