#include <iostream>
using namespace std;
void hist(int *ptr,int size);
int main(){
	int size;
	cout<<"Please enter size:";
	cin>>size;
	
	int * ptr=new int[size];
	cout<<"Please enter numbers to represent histogram:"<<endl;
	for(int i=0;i<size;i++){
		cout<<i<<":";
		cin>>*(ptr+i);
		}
	hist(ptr,size);
	return 0;
	delete [] ptr;
	system("pause");
	
}
void hist(int *ptr,int size){
	for (int i=0; i<size;i++){
		
		for(int j=0;j<ptr[i]*2;j++){
			cout<<"*";
			
		}
		cout<<ptr[i]*2;
		cout<<endl;
	}
}
