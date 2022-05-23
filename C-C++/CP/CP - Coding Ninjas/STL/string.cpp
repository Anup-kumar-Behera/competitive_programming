#include<iostream>
#include<string>
using namespace std;

int main(){
	string s = "Anup";
	string s1(s, 2, 4);
	cout<<s<<" "<<s1<<endl;
	
	string s2 = s.substr(2, 4);
	cout<<s2<<endl;
	
	cout<<s.size()<<endl;
	if(s1.compare(s2) == 0)
		cout<<s1<<" and "<<s2<<" are equal"<<endl;
	else
		cout<<s1<<" and "<<s2<<" are not equal"<<endl;	
	
}
