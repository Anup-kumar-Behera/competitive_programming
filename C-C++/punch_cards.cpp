#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int p;
	for(p = 1; p <= t; p++){
		int r, c;
		cin>>r>>c;
		r = r * 2, c = c * 2;
		vector<vector<char>> v(r+1, vector<char>(c+1, '.'));

		for(int i = 0; i <= r; i++){
			for(int j = 0; j <= c; j++){
				if(i % 2 == 0){
					if(j % 2 == 0)
						v[i][j] = '+';
					else
						v[i][j] = '-';
				}
				else{
					if(j % 2 == 0)
						v[i][j] = '|';
				}
			}
		}

		v[0][0] = v[0][1] = v[1][0] = v[1][1] = '.';
		cout<<"Case #"<<p<<":"<<endl;
		for(int i = 0; i < r+1; i++){
			string s = "";
			for(int j = 0; j < c+1; j++)
				s += v[i][j];
				cout<<s;
			cout<<endl;

		}

	}
}
