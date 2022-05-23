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
			cout<<" -> "<<*it2;
		}
		cout<<endl;
	}
	cout<<endl;
}

/*void adjacencyMatrix(map<int, vector<int> > mp, int n){
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
}*/
int main(){
	int t;
	cout<<"Enter number of test cases:  ";
	cin>>t;
	while(t--){
		cout<<endl;
		int n;
		cout<<"Enter number of nodes: ";
		cin>>n;
		
		if(n > 2){
			int prev;
			cout<<endl;
			cout<<"Enter "<<1<<" node value: ";
			cin>>prev;
			int firstNode = prev;
			
			map<int, vector<int> > mp;
			int c = 2;
			for(int i = 0; i < n-2; i++){
				int node;
				cout<<"Enter "<<c++<<" node value: ";
				cin>>node;
				if(mp[node].size() == 2)
					continue;
					mp[prev].push_back(node);
					mp[node].push_back(prev);
					prev = node;
				
			}
			int lastNode;
			cout<<"Enter "<<c<<" node value: ";
			cin>>lastNode;
			
			mp[prev].push_back(lastNode);
			mp[lastNode].push_back(prev);
			mp[lastNode].push_back(firstNode);
			mp[firstNode].push_back(lastNode);
			
			adjacencyList(mp);
			//adjacencyMatrix(mp, n);
			
			int node;
			cout<<"Enter the node value to determine its degree: ";
			cin>>node;
			cout<<mp[node].size()<<endl;
		}
		else{
			cout<<"Ring Topology not possible!\n";
		}
	}
}
