
#include <iostream>
#include <string>
using namespace std;

class ship{
protected:
	string name;
	string year;
public:
	ship(){
		name = "\0";
		year = "\0";
		
	}
	ship(string name1, string year1){
		name = name1;
		year = year1;
	}
	void setName(string name1){
		name = name1;
	}
	void setYear(string year1){
		year = year1;
	}
	string getName(){
		return name;
	}
	string getYear(){
		return year;
	}
	
	void print(){
		cout << "Name is " << name << ".Built Year is " << year << "." << endl;
	}
};

class CruiseShip : public ship {
protected:
	int pessenger_num = 0;
public:
	CruiseShip(): ship(){
		pessenger_num = 0;
	}
	CruiseShip(string name, string year, int num) : ship(name, year){
		pessenger_num = num;
	}
	void setNumber(int num){
		pessenger_num = num;
	}
	int getNumber(){
		return pessenger_num;
	}

	void print(){
		cout << "Name is " << name << ". Maximum number of pessengers is " << pessenger_num << "." << endl;
	}
};

class CargoShip : public ship {
protected:
	int capacity = 0;
public:
	CargoShip() : ship(){
		capacity = 0;
	}
	CargoShip(string name, string year, int num) : ship(name, year){
		capacity = num;
	}
	void setCapacity(int num){
		capacity = num;
	}
	int getCapacity(){
		return capacity;
	}

	void print(){
		cout << "Name is " << name << ". Cargo capacity is " << capacity << "." << endl;
	}
};

int main(){
	ship ** s = new ship *[3];
	s[0] = new ship("Titanic", "1920");
	s[1] = new CruiseShip("Oasis", "2007", 2000);
	s[2] = new CargoShip("Evergreen", "1998", 1500);

	s[0]->print();
	s[1]->print();
	s[2]->print();

	for (int i = 0; i < 3; i++){
		delete s[i];
	}

	delete[] s;
	system("pause");
	return 0;
}