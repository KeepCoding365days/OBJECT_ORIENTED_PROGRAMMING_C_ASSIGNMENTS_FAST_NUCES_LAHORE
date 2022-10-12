#include <iostream>
using namespace std;
char* unio(char* A, char*B,int size1,int size2, int &size3);
char* inter(char*A, char*B, int size1,int size2, int &size3);
char* complement(char*A,char*B, int size1, int size2, int&size3);
int main(){
	int size_1,size_2,size_inter=0,size_unio=0,size_universe=53,size_union_comp=0,size_a_comp=0,size_b_comp=0;
	char *U=new char[size_universe];
	
	for(int i=0;i<26;i++){
		U[i]=char(i+65);
	}
	for(int i=0;i<26;i++){
		U[i+26]=char(i+97);
	}
	U[52]='\0';
	
	cout<<"Universal set 'U' is:"<<endl;
	for(int i=0;i<size_universe;i++){
		cout<<U[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Please enter size of first array:"<<endl;
	cin>>size_1;
	char *A=new char[size_1];
	cout<<"Please enter elements:"<<endl;
	for(int i=0;i<size_1;i++){
		cin>>A[i];
	}
	cout<<endl;
	
	cout<<"Please enter size of second array:"<<endl;
	cin>>size_2;
	char *B=new char[size_2];
	cout<<"Please enter elements:"<<endl;
	for(int i=0;i<size_2;i++){
		cin>>B[i];
	}
	cout<<endl;
	
	char * inte=inter(A,B,size_1,size_2,size_inter);
	cout<<"Intersection of A and B is:"<<endl;
	for(int i=0;i<size_inter;i++){
		cout<<inte[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	char * uni=unio(A,B,size_1,size_2,size_unio);
	cout<<"Union of A and B is:"<<endl;
	for(int i=0;i<size_unio;i++){
		cout<<uni[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	char * union_comp=complement(U,uni,size_universe,size_unio,size_union_comp);
	cout<<"U- (AUB):"<<endl;
	for(int i=0;i<size_union_comp;i++){
		cout<<union_comp[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	char * a_comp=complement(U,A,size_universe,size_1,size_a_comp);
	cout<<"A':"<<endl;
	for(int i=0;i<size_a_comp;i++){
		cout<<a_comp[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	char * b_comp=complement(U,B,size_universe,size_2,size_b_comp);
	cout<<"B':"<<endl;
	for(int i=0;i<size_b_comp;i++){
		cout<<b_comp[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	
	delete []union_comp;
	delete []a_comp;
	delete []b_comp;
	delete []inte;
	delete [] uni;
	delete []A;
	delete []B;
	delete []U;
	
	return 0;
}
char *inter(char *A, char *B,int size1, int size2, int &size3){
	char *p = new char[size3];
	int common = 0; 
	bool check = 1;
	for (int i = 0; i < size1; i++){
		for (int j = 0; j < size2; j++){
			if (*(A + i) == *(B + j)){
				check = 1;
				for (int k = 0; k < common; k++){
					if (*(p + k) == *(B + j)){
						check = 0;
					}
				}
				if (check){
					*(p + common) = *(A + i);
					common++;
				}
				break;


			}
		}
	}
	size3 = common;
	return p;
}
char* unio(char* A, char*B,int size1,int size2, int &size3){
	char *ptr= new char[size1+size2];
	int check=0,counter=0,num=0;
	for(int i=0;i<size1;i++){
		num=A[i];
		check=1;
		for(int j=counter;j>=0 ;j--){
			if(ptr[j]==num){
				check=0;
			}
		}
			if(check){
				ptr[counter]=num;
				counter++;
			}
		
		
	}
	for(int i=0;i<size2;i++){
		num=B[i];
		check=1;
		for(int j=counter;j>=0;j--){
			if(ptr[j]==num){
				check=0;
				break;
			}
		}
			if(check){
				ptr[counter]=num;
				counter++;
			}
		}
	
	size3=counter;
	return ptr;
}

char* complement(char*A,char*B, int size1, int size2, int&size3){
	char*ptr=new char[size1];	
	int number=0;
	bool check=0;
	
	for(int i=0;i<size1;i++){
		number=A[i];
		check=1;
		for(int j=0;j<size2;j++){
			if (B[j]==number){
				check=0;
				break;
			}
		}
		if(check){
			ptr[size3]=number;
			size3++;
		}
	}
	return ptr;
}
