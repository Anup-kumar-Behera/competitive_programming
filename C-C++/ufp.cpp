//	FUNCTION TO CALCULATE UNADJUSTED FUNCTION POINT (UFP) 

#include<iostream>
#define N 1000
using namespace std;

void calcUFP(int arr[][N]){
	int weights[][3] = {{3, 4, 6},
						{4, 5, 7},
						{3, 4, 6},
						{7, 10, 15},
						{5, 7, 10}};
	
	int ufp = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 3; j++){
			int temp = arr[i][j];
			ufp += temp * weights[i][j];
		}
	}
	cout<<"\nUFP is: "<<ufp<<endl;
}

void inputs(){
	int arr[5][N];
	
	string str[5] = {"Number of inputs: ", "Number of outputs: ", "Number of inquiries: ", "User files: 	", "External Interfaces: "};
	for(int i = 0; i < 5; i++){
		cout<<str[i]<<endl;
		for(int j = 0; j < 3; j++){
			if(j == 0){
				cout<<"Enter values (simple): ";
				cin>>arr[i][j];
			}
			else if(j == 1){
				cout<<"Enter values (average): ";
				cin>>arr[i][j];
			}
			else if(j == 2){
				cout<<"Enter values (complex): ";
				cin>>arr[i][j];
			}
		}
		cout<<endl;
	}
	
	cout<<"Entered values are: \n";
	cout<<"			  	simple	   	average	    	complex\n";
	for(int i = 0; i < 5; i++){
		cout<<str[i]<<"		";
		for(int j = 0; j < 3; j++){
			cout<<"  "<<arr[i][j]<<"		";
		}
		cout<<endl;
	}
	calcUFP(arr);
}


int main(){
	
	inputs();
	
}
