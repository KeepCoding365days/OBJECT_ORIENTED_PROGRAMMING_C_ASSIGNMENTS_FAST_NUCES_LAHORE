#include "Q2.h"
#include <iostream>
using namespace std;

int main() {
	int std_size = 0;
	char* Roll_no_arg = new char[size_array];
	
	char* Name_arg = new char[size_array];
	
	char* Cnic_arg = new char[size_array];
	char* Degree_arg = new char[size_array];
	
	char* address_arg = new char[size_address];
	cout << "Please enter number of students: ";
	cin >> std_size;
	cin.ignore();
	Student* ptr = new Student[std_size];
	
	for (int i = 0;i < std_size;i++) {
		cout << "Enter Roll Number of " << i + 1 << "th student:";
		cin.getline(Roll_no_arg, size_array);
		ptr[i].set_roll_no(Roll_no_arg);
	}

	for (int i = 0;i < std_size;i++) {
		cout << "Enter name of " << i + 1 << "th student:";
		cin.getline(Name_arg, size_array);
		ptr[i].set_name(Name_arg);
	}

	for (int i = 0;i < std_size;i++) {
		cout << "Enter cnic of " << i + 1 << "th student:";
		cin.getline(Cnic_arg, size_array);
		ptr[i].set_cnic(Cnic_arg);
	}

	for (int i = 0;i < std_size;i++) {
		cout << "Enter degree of " << i + 1 << "th student:";
		cin.getline(Degree_arg, size_array);
		ptr[i].set_degree(Degree_arg);
	}

	for (int i = 0;i < std_size;i++) {
		cout << "Enter address of " << i + 1 << "th student:";
		cin.getline(address_arg, size_address);
		ptr[i].set_address(address_arg);
	}
	cout << endl;

	for (int i = 0;i < std_size;i++) {
		cout << "Student " << i + 1 << ":" << endl;
		ptr[i].Display();
		cout << endl;
	}
	delete[] Roll_no_arg;
	delete[] Cnic_arg;
	delete[] Name_arg;
	delete[] Degree_arg;
	delete[] address_arg; 

	system("pause");
	return 0;
}

