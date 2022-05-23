//Count of sticks required to represent the given string

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int str[] = {6, 7, 4, 6, 5, 4, 6, 
                 5, 2, 4, 4, 3, 6, 6, 
                 6, 5, 7, 6, 5, 3, 5, 
                 4, 6, 4, 3, 4};
	int num[] = {6, 2, 5, 5, 4, 5, 6, 
                 3, 7, 6 };
                 
    char string[40];
    cout<<"Enter a string: ";
    cin>>string;
    
    cout<<endl<<"Entered string is : "<<string<<endl;
    int k = strlen(string),s = 0;
    for(int i = 0;i < k;i++)
    {
    	char ch = string[i];
    	
    	if(ch >= 'A' && ch <= 'Z' )
    		s = s+str[ch-'A'];
    	else if(ch >= '0' && ch<= '9')
    		s = s + num[ch-'0'];
	}
	//int p = string[0];
	cout<<"\n"<<s;
	return 0;
}
