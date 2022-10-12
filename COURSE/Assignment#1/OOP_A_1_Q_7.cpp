//program to find union of two arrays
#include <iostream>
using namespace std;

int *Union(int* p1, int *p2, int size1, int size2,int &size3);

int main(){
	int size1=0,size2,size3=0;
	
	cout<<"Enter size of first array:";
	cin>>size1;
	
	cout<<"Enter size of second array:";
	cin>>size2;
	
	int *p1=new int[size1];
	int *p2=new int[size2];
	
	cout<<"Enter elements of first array:"<<endl;
	
	for(int i=0;i<size1;i++){
		cin>>*(p1+i);
	}
	
	cout<<"Enter elements of second array:"<<endl;
	
	for(int i=0;i<size2;i++){
		cin>>*(p2+i);
	}
	
	int *Unio=Union(p1,p2,size1,size2,size3);
	
	cout<<"Union of two arrays is:"<<endl;
	
	for(int i=0;i<size3;i++){
		cout<<*(Unio+i)<<endl;
	}
	delete []Unio;
	delete []p1;
	delete []p2;
	
}

int *Union(int* p1, int *p2, int size1, int size2,int &size3){
	size3=size1+size2;
	int *Unio=new int[size3];
	bool exist;
	size3=0;
	
	for(int i=0; i<size1;i++){
		exist=false;
		
		for(int j=0;j<size3;j++){
			if(*(p1+i)==*(Unio+j)){
				exist=true;
			}
		}
		
		if(!exist){
			*(Unio+size3)=*(p1+i);
			size3++;
		}
	}
	
	//adding values of second array
	for(int i=0; i<size2;i++){
		exist=false;
		
		for(int j=0;j<size2;j++){
			if(*(p2+i)==*(Unio+j)){
				exist=true;
			}
		}
		
		if(!exist){
			*(Unio+size3)=*(p2+i);
			size3++;
		}
	}
	
	//shrinking array
	int* union_new=new int [size3];
	
	for(int i=0;i<size3;i++){
		*(union_new+i)=*(Unio+i);
	}
	
	delete[] Unio;
	return union_new;
}

