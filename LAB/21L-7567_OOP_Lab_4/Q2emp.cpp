
#include "Q2.h"
#include<iostream>
using namespace std;

Student::Student() {
	*roll_no = 0;
	*name = 0;
	*cnic = 0;
	*degree = 0;
	*address = 0;
}
Student::Student(char* roll_no_arg, char* name_arg, char* cnic_arg, char* degree_arg, char* address_arg) {
	for (int i = 0;roll_no_arg[i] != '\0';i++) {
		*(roll_no + i) = *(roll_no_arg+i);
		*(roll_no + i + 1) = '\0';
	}

	for (int i = 0;roll_no_arg[i] != '\0';i++) {
		*(roll_no + i) = *(roll_no_arg+i);
		*(roll_no + i + 1) = '\0';
	}

	for (int i = 0;name_arg[i] != '\0';i++) {
		*(name + i) = *(name_arg+i);
		*(name + i + 1) = '\0';
	}

	for (int i = 0;cnic_arg[i] != '\0';i++) {
		*(cnic + i) = *(cnic_arg+i);
		*(cnic + i + 1) = '\0';
	}

	for (int i = 0;address_arg[i] != '\0';i++) {
		*(address + i) = *(address_arg+i);
		*(address + i + 1) = '\0';
	}
}
Student::Student(char* roll_no_arg, char* name_arg, char* cnic_arg) {
	for (int i = 0;roll_no_arg[i] != '\0';i++) {
		*(roll_no + i) = *(roll_no_arg+i);
		*(roll_no + i + 1) = '\0';
	}
	for (int i = 0;name_arg[i] != '\0';i++) {
		*(name + i) = *(name_arg+i);
		*(name + i + 1) = '\0';
	}
	for (int i = 0;cnic_arg[i] != '\0';i++) {
		*(cnic + i) = *(cnic_arg+i);
		*(cnic + i + 1) = '\0';
	}
	*degree = 0;
	*address = 0;
}


void Student::set_roll_no(char* roll_no_arg) {
	if (*roll_no == 0) {
		roll_no = new char[size_array];
	}
	for (int i = 0;roll_no_arg[i] != '\0';i++) {
		*(roll_no + i) = *(roll_no_arg+i);
		*(roll_no + i + 1) = '\0';
	}
}
void Student::set_name(char* name_arg) {
	if (*name == 0) {
		name = new char[size_array];
	}
	for (int i = 0;name_arg[i] != '\0';i++) {
		*(name + i) = *(name_arg+i);
		*(name + i + 1) = '\0';
	}
}
void Student::set_cnic(char* cnic_arg) {
	if (*cnic == 0) {
		cnic = new char[size_array];
	}
	for (int i = 0;cnic_arg[i] != '\0';i++) {
		*(cnic + i) = *(cnic_arg + i);
		*(cnic + i + 1) = '\0';
	}
}
void Student::set_degree(char* degree_arg){
	if (*degree == 0) {
		degree = new char[size_array];
	}
	for (int i = 0;degree_arg[i] != '\0';i++) {
		*(degree + i) = *(degree_arg + i);
		*(degree + i + 1) = '\0';
	}
}
void Student::set_address(char* address_arg) {
	if (*address == 0) {
		address = new char[size_array];
	}
	for (int i = 0;address_arg[i] != '\0';i++) {
		*(address + i) = *(address_arg + i);
		*(address + i + 1) = '\0';
	}
}

char* Student::get_roll_no() {
	return roll_no;
}


char* Student:: get_name() {
	return name;
}

char* Student::get_cnic() {
	return cnic;
}
char* Student::get_degree() {
	return degree;
}
char* Student::get_address() {
	return address;
}

void Student::Display() {
	cout << "Roll Number is: ";
	for (int i = 0; roll_no[i] != '\0';i++) {
		cout << roll_no[i];
	}
	cout << endl;

	cout << "Name is: ";

	for (int i = 0; name[i] != '\0';i++) {
		cout << name[i];
	}

	cout << endl;
	cout << "Cnic number: ";
	
	for (int i = 0; cnic[i] != '\0';i++) {
		cout << cnic[i];
	}
	cout << endl;
	cout << "Degree is: ";
	for (int i = 0; degree[i] != '\0';i++) {
		cout << degree[i];
	}
	cout << endl;
	cout << "Address is: ";
	for (int i = 0; address[i] != '\0';i++) {
		cout << address[i];
	}
	cout << endl;
}


Student::~Student() {
	delete[] roll_no;
	delete[] name;
	delete[] cnic;
	delete[] degree;
	delete[] address;
}
