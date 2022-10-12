#include "Q1.h"
#include<iostream>
using namespace std;
Employee::Employee(){
	id = 0;
	Name = 0;
	Dept = 0;
}
Employee::Employee(int id_arg, char* name_arg, char*dept_name_arg){
	id = id_arg;
	for (int i = 0; name_arg[i] != '\0'; i++){
		*(Name + i) = *(name_arg + i);
	}
	for (int i = 0; dept_name_arg[i] != '\0'; i++){
		*(Dept + i) = *(dept_name_arg + i);
	}
}
Employee::Employee(int id_arg, char* name_arg){
	id = id_arg;
	for (int i = 0; name_arg[i] != '\0'; i++){
		*(Name + i) = *(name_arg + i);
	}
	for (int i = 0; i < size_dept; i++){
		*(Dept + i) = ' ';
	}
}
void Employee::set_id(int id_arg){
	id = id_arg;
}
void Employee::set_name(char * name_arg){
	if (Name == 0){
		Name = new char[size_name];
	}
	for (int i = 0; name_arg[i] != '\0'; i++){
		*(Name + i) = *(name_arg + i);
		*(Name + i + 1) = '\0';
	}
}
void Employee::set_dept_name(char * dept_name_arg){
	if (Dept == 0){
		Dept = new char[size_dept];
	}
	for (int i = 0; dept_name_arg[i] != '\0'; i++){
		*(Dept + i) = *(dept_name_arg + i);
		*(Dept + i + 1) = '\0';
	}
}
int	Employee::get_id(){
	return id;
	}
char* Employee::get_name(){
	return Name;
}
char* Employee::get_dept_name(){
	return Dept;
}
void Employee::Display(){
	cout << "Id is: " << id << endl;
	cout << "Name is: ";
	for (int i = 0; Name[i] != '\0'; i++){
		cout << *(Name + i);
	}
	cout << endl;
	cout << "Department name is: ";
	for (int i = 0; Dept[i] != '\0'; i++){
		cout << *(Dept + i);
	}
	cout << endl;
}
Employee:: ~Employee(){
	delete[] Name;
	delete[] Dept;
}
