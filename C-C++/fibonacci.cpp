#include<iostream>
using namespace std;

int fibonacci(int n){
	if(n == 0 || n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
int fib(int n){
	int arr[n+1];
	arr[0] = arr[1] = 1;
	
	for(int i = 2; i <= n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}
int main(){
	int n;
	int p;
	do{
		cout<<"Enter value of n: ";
		cin>>n;cout<<fibonacci(n)<<endl;
		cout<<fib(n)<<endl;
		cout<<"\ndo you want to continue (0/1): ";
		cin>>p;
	}while(p);

}
