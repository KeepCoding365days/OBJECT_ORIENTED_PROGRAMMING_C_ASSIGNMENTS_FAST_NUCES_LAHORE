//Program to grow a dynamic array
#include <iostream>
using namespace std;
int *growArray(int* ptr, int size,int size2);
int main(){
	int size, size2=0;
	cout<<"Enter size of Array:";
	cin>>size;
	
	int *ptr=new int[size];
	
	cout<<"Enter elements of array:"<<endl;
	
	for(int i=0;i<size;i++){
		cin>>*(ptr+i);
	}
	
	again:	//repeat if user enter wrong input
	cout<<"Enter new size to grow array:";
	cin>>size2;
	
	if(size2<size){
		cout<<"Wrong Input."<<endl;
		goto again;
	}
	else{
	
	ptr=growArray(ptr,size,size2);
	
	cout<<"New Array:"<<endl;
	
	for(int i=0;i<size2;i++){
		cout<<*(ptr+i)<<endl;
	}
	

	delete[] ptr;
}
	system ("pause");
	return 0;
}

int *growArray(int* ptr, int size,int size2){
	int *grow=new int [size2];
	
	for (int i=0;i<size;i++){
		*(grow+i)=*(ptr+i);
	}
	
	cout<<"Enter new elements to add in Array:"<<endl;
	
	for (int i=size;i<size2;i++){
		cin>>*(grow+i);
	}
	
	delete[]ptr;
	return grow;
}
