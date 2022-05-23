#include<bits/stdc++.h>
using namespace std;
#define MAX 100

bool isSafe(int board[][MAX], int i, int j, int n){
	for(int row = 0; row < i; row++){
		if(board[row][j] == 1)
			return false;
	}
	
	int x = i, y = j;
	while(x >= 0 && y >= 0){
		if(board[x][y] == 1)
			return false;
		x--;
		y--;
	}
	
	x = i, y = j;
	while(x >= 0 && y < n){
		if(board[x][y] == 1)
			return false;
		x--;
		y++;
	}
	
	return true;
}
void dsp(int board[][MAX], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 1)
				cout<<"Q ";
			else
				cout<<"_ ";
		}
		cout<<endl;
	}
}
bool solveNQueen(int board[][MAX], int i, int n){
	if(i == n){
		
		return true;
	}
	for(int j = 0; j < n; j++){
		if(isSafe(board, i, j, n)){
			board[i][j] = 1;
			
			bool nextPossible = solveNQueen(board, i+1, n);
			if(nextPossible)
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}
int main(){
	int n;
	
	do{
		cout<<"Enter an integer: ";
		cin>>n;
		
		int board[n][MAX] = {0};
		solveNQueen(board, 0, n);
		dsp(board, n);
		cout<<endl;
	}while(n != 0);
}
