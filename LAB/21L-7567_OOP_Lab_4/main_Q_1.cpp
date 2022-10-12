#include "Q1.h"
#include <iostream>
using namespace std;
int main(){
	int size = 0,id=0;
	char* name= new char[size_name];
	char *dept_name=new char[size_dept];
	cout << "Enter size of Employees:" << endl;
	cin >> size;
	Employee *ptr = new Employee[size];
	for (int i = 0; i < size; i++){
		cout << "Enter id of " << i + 1 << "th employee:" << endl;
		cin >> id;
		cin.ignore();
		ptr[i].set_id(id);
	}
	for (int i = 0; i < size; i++){
		cout << "Enter name of " << i + 1 << "th employee:" << endl;
		cin.getline(name, 31);
		ptr[i].set_name(name);
	}
	for (int i = 0; i < size; i++){
		cout << "Enter department name of " << i + 1 << "th employee:" << endl;
		cin.getline(dept_name, size_name);
		ptr[i].set_dept_name(dept_name);
	}
	for (int i = 0; i < size; i++){
		cout << "Employee " << i + 1 << ":" << endl;
		ptr[i].Display();
		cout << endl;
	}
	delete[]name;
	delete[]dept_name;
	system("pause");
	return 0;
}