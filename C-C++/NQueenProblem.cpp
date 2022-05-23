#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
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
void dsp(int board[][10],int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 1)
				cout<<"Q ";
			cout<<"_ ";
		}
		cout<<endl;
	}
}
bool solveNQueen(int board[][10], int i, int n){
	if(i == n){
		dsp(board, n);
		cout<<endl;
		return false;
	}
	//Recursive Case
	//Try to place the quenn in the current row
	for(int j = 0; j < n; j++){
		// I have to check if i, j place is safe or not
		if(isSafe(board, i, j, n)){
			//place the queen
			board[i][j] = 1;
			
			bool nextQueen = solveNQueen(board, i+1, n);
			if(nextQueen)
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int board[10][10] = {0};
	solveNQueen(board, 0, n);
	dsp(board, n);
}
