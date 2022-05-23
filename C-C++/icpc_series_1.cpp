#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2){
	int a = v1[0] + v1[1] + v1[2];
	int b = v2[0] + v2[1] + v2[2];
	return (a < b);
}
int main(){
	int n = 3;
	//cin>>n;
	vector<vector<int> > v;
	
	for(int i = 0; i < 3; i++){
		vector<int> temp;
		for(int j = 0; j < 3; j++){
			int a, b, c;
			cin>>a>>b>>c;
			
			temp.push_back(a);
			temp.push_back(b);
			temp.push_back(c);
		}
		
		
		v.push_back(temp);
	}
	
	cout<<"Before sorting:\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	sort(v.begin(), v.end(), compare);
	
	cout<<"After sorting:\n";
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
