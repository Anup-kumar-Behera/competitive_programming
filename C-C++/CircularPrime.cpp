#include<iostream>
#include<cmath>

using namespace std;

bool CheckPrime(int n)
{
	if(n < 0)
		return false;
	int i = 2,c = 1;
	while(i < 10)
	{
		if( n % i == 0)
			c++;
		i++;
	}
	if(c <= 2)
		return true;
	return false;
}

bool CheckCircular(int n)
{
	int count = 0, temp = n; 
    while (temp) 
	{ 
        count++; 
        temp /= 10; 
    } 
  
    int num = n; 
    while (CheckPrime(num)) 
	{ 
        int rem = num % 10; 
        int div = num / 10; 
        num = (pow(10, count - 1)) * rem + div; 
        if (num == n) 
            return true; 
    } 
    return false; 
}

int main()
{
	int n;
	cout<<"Enter any Integer number: ";
	cin>>n;
	
	if(CheckCircular(n) == true)
		cout<<endl<<n<<" is a Circular prime number.\n";
	else
		cout<<endl<<n<<" is not a Circular prime number.\n";
	
	return 0;	
}
