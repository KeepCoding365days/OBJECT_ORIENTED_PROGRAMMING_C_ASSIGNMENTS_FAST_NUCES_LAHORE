 //program to output second largest number
#include <iostream>
using namespace std;
int second_largest( int * ptr,int size);

int main(){
	int size=0, num=0;
	
	cout<<"Please enter size of array: "<<endl;
	cin>>size;
	
	int *ptr=new int [size];
	
	cout<<"Please enter numbers"<<endl;
	
	for(int i=0;i<size;i++){
		cin>>*(ptr+i);
	}
	
	cout<<"Second largest number is:";
	
	num=second_largest(ptr,size);
	
	cout<<num<<endl;
	
	delete []ptr;
	system("pause");
	return 0;
}

int second_largest( int * ptr, int size){
	int num=0,temp=0;
	num=*ptr; //storing first index of ptr at num
	for(int i=0; i<size;i++){
		if(*(ptr+i)>num){
			temp=num;
			num=*(ptr +i);
		}
		if (*(ptr+i)!=num && *(ptr+i)>temp){
			temp=*(ptr+i);
		}
	}
	return temp;
}
