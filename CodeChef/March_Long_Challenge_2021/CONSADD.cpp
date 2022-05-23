#include <bits/stdc++.h>
#define MAX 19999
using namespace std;

bool solve(long int m1[MAX][MAX], long int m2[MAX][MAX], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(m1[i][j] != m2[i][j])
                return false;
            else{
                
            }
        }
    }
    return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int r, c, x;
	    cin>>r>>c>>x;
	    
	    long int m1[MAX][MAX], m2[MAX][MAX];
	    
	    for(int i = 0; i < r; i++)
	        for(int j = 0; j < c; j++)
	            cin>>m1[i][j];
	   
	    for(int i = 0; i < r; i++)
	        for(int j = 0; j < c; j++)
	            cin>>m2[i][j];
	    
	    bool ans = solve(m1, m2, r, c);
	    if(r < x && c < x){
	    	
	    	if(solve(m1, m2, r, c))
	    		cout<<"Yes"<<endl;
	    	else
	    		cout<<"No"<<endl;
		}
		else if(r < x){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c-x+1; j++){
					if(m1[i][j] == m2[i][j])
						continue;
					else{
						long int diff = m2[i][j] - m1[i][j];
						m1[i][j] += diff;
						int k = 1;
						
						while(k < x){
							m1[i][j+k] += diff;
							k++;
						}
					}
						
				}
			}
			if(solve(m1, m2, r, c))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else if(c < x){
			for(int i = 0; i < c; i++){
				for(int j = 0; j < r-x+1; j++){
					if(m1[j][i] == m2[j][i])
						continue;
					else{
						long int diff = m2[j][i] - m1[j][i];
						m1[j][i] += diff;
						int k = 1;
						
						while(k < x){
							m1[j + k][i] += diff;
							k++;
						}
					}
						
				}
			}
			if(solve(m1, m2, r, c))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else if(c >= x && r >= x){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c-x+1; j++){
					if(m1[i][j] == m2[i][j])
						continue;
					else{
						long int diff = m2[i][j] - m1[i][j];
						m1[i][j] += diff;
						int k = 1;
						
						while(k < x){
							m1[i][j + k] += diff;
							k++;
						}
					}
						
				}
			}
			for(int i = 0; i < c; i++){
				for(int j = 0; j < r-x+1; j++){
					if(m1[j][i] == m2[j][i])
						continue;
					else{
						long int diff = m2[j][i] - m1[j][i];
						m1[j][i] += diff;
						int k = 1;
						
						while(k < x){
							m1[j + k][i] += diff;
							k++;
						}
					}
				}
			}
			if(solve(m1, m2, r, c))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}

