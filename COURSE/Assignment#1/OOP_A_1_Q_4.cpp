//Program to find minimum numbers by columns
#include <iostream>
using namespace std;

int * minCol_wise(int ** ptr, int rows, int cols);

int main(){
	int rows,cols,*min;
	cout<<"Please enter number of rows:";
	cin>>rows;
	cout<<"Please enter number of columns:";
	cin>>cols;
	int ** ptrs= new int*[rows];
	for (int i=0;i<rows;i++){
		*(ptrs+i)=new int [cols];
	}
	cout<<"Please enter values for following indexes:"<<endl;
	for (int i=0; i<rows;i++){
		for (int j=0; j<cols; j++){
			cout<<i<<j<<":";
			cin>>ptrs[i][j];
		}
	}
	
	min=minCol_wise(ptrs,rows,cols);
	cout<<"Column wise minimum numbers are as follow:"<<endl;
	for (int i=0;i<cols;i++){
		cout<<*(min+i)<<endl;
	}
	for(int i=0;i<rows;i++){
		delete []ptrs[i];
	}
	delete []ptrs;
	delete []min;
	system("pause");
	return 0;
}

int * minCol_wise(int ** ptr, int rows, int cols){
	int min=0;
	int *arr=new int[cols];
	
	for(int j=0; j<cols;j++){
		min=ptr[0][j];
		for(int i=0; i<rows;i++){
			if(ptr[i][j]<min){
				min=ptr[i][j];
			}
		}
		*(arr+j)=min;
	}
	
	return arr;
}


