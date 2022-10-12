#include <iostream>
using namespace std;
int main(){
	int long value1=200000;
    int long value2;
	int long *longPtr;
	
	longPtr=&value1;
	cout<<"Value of longPtr pointing to value1:"<<*longPtr<<endl;
	
	value2=*longPtr;
	cout<<"Value2:"<<value2<<endl;
	
	cout<<"Address of Value1:"<<&value1<<endl;
	
	cout<<"Address stored in longPtr:"<<longPtr<<endl;
	//Same
	//delete every pointer
	system("pause");
	return 0;
}
