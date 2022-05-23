#include<bits/stdc++.h>
#define N 1000
using namespace std;

void adjacencyList(map<int, vector<int> > mp){
	cout<<"\n Adjacency List Representation of the Star Topology: \n";
	map<int, vector<int> >::iterator it;
	vector<int>::iterator it2;
	for(it = mp.begin(); it != mp.end(); it++){
		cout<<"	"<<it->first<<" ";
		for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
			cout<<" -> "<<*it2<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void adjacencyMatrix(map<int, vector<int> > mp, int n, int hub){
	cout<<"\n Adjacency Matrix Representation of the Star Topology: \n";
	map<int, vector<int> >::iterator i;
	vector<int>::iterator j;
	
	cout<<"		";
	for(i = mp.begin(); i != mp.end(); i++){
		cout<<i->first<<"    ";
	}
	cout<<endl<<endl;
	for(i = mp.begin(); i != mp.end(); i++){
		cout<<"	"<<i->first<<"       ";
		for(int j = 0; j < n; j++){
			if(i->first != hub){
				if(j == hub)
					cout<<1<<"    ";
				else
					cout<<0<<"    ";
			}
			else
				cout<<1<<"    ";
		}
		
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	int t;
	cout<<"Enter number of test cases:  ";
	cin>>t;
	while(t--){
		cout<<endl;
		int n;
		cout<<"Enter number of nodes: ";
		cin>>n;
		
		int hub;
		cout<<"Enter value for the hub: ";
		cin>>hub;
		
		map<int, vector<int> > mp;
		for(int i = 0; i < n-1; i++){
			int node;
			cin>>node;
			mp[hub].push_back(node);
			mp[node].push_back(hub);
			
		}
		
		adjacencyList(mp);
		adjacencyMatrix(mp, n, hub);
		
		int node;
		cout<<"Enter the node value to determine its degree: ";
		cin>>node;
		cout<<mp[node].size()<<endl;
	}
}
