#include <iostream>
using namespace std;
void shift(int *x, int *y, int *z);
int main(){
	int x=0,y=0,z=0;
	cout<<"Please enter value of x:"<<endl;
	cin>>x;
	
	cout<<"Please enter value of y:"<<endl;
	cin>>y;
	
	cout<<"Please enter value of z:"<<endl;
	cin>>z;
	
	shift(&x,&y,&z);
	
	cout<<"Value of x is "<<x<<"."<<endl;
	cout<<"Value of y is "<<y<<"."<<endl;
	cout<<"Value of z is "<<z<<"."<<endl;
	
	system("pause");
	
	return 0;
}

void shift(int *x, int *y, int *z){
	int temp=0;
	temp=*y;
	*y=*x;
	int temp1=*z;
	*z=temp;
	*x=temp1;
	
}

