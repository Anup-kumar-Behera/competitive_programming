#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of packets: ";
	cin>>n;
	cout<<endl;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		v.push_back(i+1);
	}
	
	cout<<endl<<"Assuming that every even packet sent by the sender\n will not receive any acknowledgement.\n\n";
	
	int w;
	cout<<"Enter the size of the window (w <= n): ";
	cin>>w;
	
	
	int ack = 0, p = 0, i = 0;
	while(i < n){
		if(p == 0){
			for(int j = i; j < i+w; j++){
				cout<<"packet no: "<<v[j]<<" is sent.\n";
			}
			p = 1;
		}
	
			if(i%2){
				cout<<"Acknowledgement not received for packet no: "<<v[i]<<".\n";
				for(int j = i; j < i+w && i+w <= n; j++){
					cout<<"Retransmitting packet no: "<<v[j]<<endl;
				}
				cout<<"Acknowledgement Received for packet no: "<<v[i]<<".\n";
				if(i+w <= n-1){
					cout<<"packet no: "<<v[i+w]<<" is sent.\n";
				}
				i++;
			}
			else{
				cout<<"Acknowledgement Received for packet no: "<<v[i]<<".\n";
				if(i+w <= n-1){
					cout<<"packet no: "<<v[i+w]<<" is sent.\n";
				}
				i++;
			}
		
	}
	
}






