#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;
typedef long long int ll;

string to_binary(ll num){
	
	string bin = "";
	while (num){
		if (num & 1)
			bin = "1" + bin;
		else
			bin = "0" + bin;
		num = num>>1;
	}
	return bin;
}

string generate(int m){
	string g = "1";
	for(int i = 0; i < m-2; i++){
		g += "0";
	}
	g+= "1";
	g+= "1";
	
	return g;
}
ll to_decimal(string bin){
	ll num = 0;
	for (int i=0; i<bin.length(); i++){
		if (bin.at(i)=='1')
			num += 1 << (bin.length() - i - 1);
	}
	return num;
}

void solveCrc(string dataword, string generator, string &a, string &b){
	int l_gen = generator.length();
	ll gen = to_decimal(generator);

	ll dword = to_decimal(dataword);

	ll dividend = dword << (l_gen-1);	 

	int shft = (int) ceill(log2l(dividend+1)) - l_gen; 
	ll rem;

	while ((dividend >= gen) || (shft >= 0)){

		rem = (dividend >> shft) ^ gen;			 
		dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);

		shft = (int) ceill(log2l(dividend + 1)) - l_gen;
	}

	ll codeword = (dword << (l_gen - 1)) | dividend;

	
	a = to_binary(dividend);
	b = to_binary(codeword);

	
}

int main(){
	string s;
	cout<<"Enter the value of k and m such that (m < k): ";
	int k, m;
	cin>>k>>m;
	cout<<"\nEnter a binary string of length k:  ";
	cin>>s;
	
	string g = generate(m);
	cout<<"g: "<<g<<endl;
	string a, b;
	solveCrc(s, g, a, b);
	cout<<"\nreminder: "<<a<<"  bit-stream: "<<b;
	
	cout<<"\n\nEnter the value of the index (index < "<<b.length()<<") to invert the bit: ";
	int ind;
	cin>>ind;
	
	if(b[ind] == '1')
		b.replace(ind, 1, "0");
	else
		b.replace(ind, 1, "1");
	cout<<"After inverting bit at index "<<ind<<" :"<<b<<endl;
	
	string c, d;
	solveCrc(b, g, c, d);
		
	if(c.length())
		cout<<"\nError Encountered\n";
	else
		cout<<"\nNo error encountered\n";
	return 0;
}

