 //Program to sort dynamic array
#include <iostream>
using namespace std;

void sort(int *ptr, int size);

int main(){
	int size=0;
	cout<<"Enter size of array:";
	cin>>size;
	int *ptr=new int[size];
	cout<<"Enter elements of array:"<<endl;
	
	for (int i=0; i<size;i++){
		cin>>*(ptr+i);
		
	}
	sort(ptr,size);
	cout<<"Sorted Array is:"<<endl;
	for (int i=0;i<size;i++){
		cout<<*(ptr+i)<<endl;
	
	}
	delete []ptr;
	system("pause");
	return 0;
}

void sort(int*ptr, int size){
	int min=0,temp=0;
	min=*ptr;
	for(int i=0;i<size;i++){
		min=*(ptr+i);	 
		for(int j=i;j<size;j++){
			if(*(ptr+j)<min){
				min=*(ptr+j);
				temp=*(ptr+j);
				*(ptr+j)=*(ptr+i);
				*(ptr+i)=temp;
			}
		}
	}
}
