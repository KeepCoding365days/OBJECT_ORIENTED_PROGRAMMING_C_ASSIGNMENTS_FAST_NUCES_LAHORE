//Program to find minimum numbers by row
#include <iostream>
using namespace std;
int * minRow_wise(int **ptr,int rows, int cols);
int main(){
	int *min=0,rows=0,cols=0;
	cout<<"Enter number of rows:";
	cin>>rows;
	cout<<"Enter number of columns:";
	cin>>cols;
	
	int**ptrs=new int* [rows];
	
	for(int i=0;i<5;i++){
		*(ptrs+i)=new int [cols];
	}
	
	cout<<"Enter elements of array at following indexes:"<<endl;
	for (int i=0; i<rows;i++){
		for (int j=0; j<cols;j++){
			cout<<i<<j<<":";
			cin>>ptrs[i][j];
		}
	}
	
	min= minRow_wise(ptrs,rows,cols);
	
	cout<<"Minimum Values"<<endl;
	for(int i=0;i<rows;i++){
		cout<<*(min+i)<<endl;
	}
	for(int i=0;i<rows;i++){
	
	delete[]ptrs[i];
	}
	delete[]ptrs;
	delete[]min;
	system("pause");
	return 0;
}

int * minRow_wise(int **ptr,int rows, int cols){
	int * array=new int[rows];
	int min=0;
	for (int i=0;i<rows;i++){
		min=ptr[i][0];
		for(int j=0;j<cols;j++){
			if(ptr[i][j]<min){
				min=ptr[i][j];
			}
		}
		*(array+i)=min;
	}
	return array;
}
