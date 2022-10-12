#include <string>
#include <iostream>
using namespace std;

//Creating sales class
class sales {
protected:
	float monthly_sales[3];
public:
	sales() {
		for (int i = 0;i < 3;i++) {
			monthly_sales[i] = 0;
		}
	}
	void putData() {
		cout << "Enter monthly sales of last three months starting with last month.";
		cout << endl;
		for (int i = 0;i < 3;i++) {
			cin >> this->monthly_sales[i];
		}
	}
	void getData() {
		cout << "Monthly sales of this publication in last three months starting with last month:";
		cout << endl;
		for (int i = 0;i < 3;i++) {
			cout << this->monthly_sales[i] << "$" << endl;;
		}
	}
};

//creating publication class
class publication {
protected:
	string title;
	float price;
public:
	publication() {
		title = '\0';
		price = 0;
	}
	publication(string title, float price) {
		this->title = title;
		this->price = price;
	}
	void putData() {

		cout << "Please enter title of Publication:" << endl;
		getline(cin, this->title);

		cout << "Please enter price of Publication:" << endl;
		cin >> this->price;
	}

	void getData() {
		cout << "Title of Publication is: ";
		cout << this->title;
		cout << endl;

		cout << "Price of Publication is: ";
		cout << this->price;
		cout << endl;
	}

};

//creating book class
class book : public publication, public sales {
protected:
	int page_count;

public:
	book() :publication(), sales() {
		page_count = 0;
	}

	book(int val) : publication(), sales() {
		page_count = val;
	}

	book(string title, int price, int val) :publication(title, price),sales() {
		page_count = val;
	}

	void putData() {
		cin.ignore();
		cout << "Please enter title of book:" << endl;
		getline(cin, this->title);

		cout << "Please enter price of book:" << endl;
		cin >> this->price;

		cout << "Please enter page count of book:" << endl;
		cin >> this->page_count;

		sales::putData();
	}

	void getData() {
		cout << "Title of book is: ";
		cout << this->title;
		cout << endl;

		cout << "Price of book is: ";
		cout << this->price;
		cout << endl;

		cout << "Page count of book is: ";
		cout << this->page_count;
		cout << endl;

		sales::getData();
	}
};
//creating tape class

class tape : public publication, public sales {
protected:
	float play_time;

public:
	tape() :publication(), sales() {
		play_time = 0;
	}

	tape(int val) : publication(),sales() {
		play_time = val;
	}

	tape(string title, int price, int val) :publication(title, price), sales() {
		play_time = val;
	}

	void putData() {
		cin.ignore();
		cout << "Please enter title of tape:" << endl;
		getline(cin, this->title);

		cout << "Please enter price of tape:" << endl;
		cin >> this->price;

		cout << "Please enter play time of tape:" << endl;
		cin >> this->play_time;

		sales::putData();
	}

	void getData() {
		cout << "Title of tape is: ";
		cout << this->title;
		cout << endl;

		cout << "Price of tape is: ";
		cout << this->price;
		cout << endl;

		cout << "Play time of tape is: ";
		cout << this->play_time;
		cout << endl;

		sales::getData();
	}
};

//creating disk class
class disk : public publication, public sales {
protected:
	string disk_type;

public:
	disk() :publication() , sales() {
		disk_type='\0';
	}

	disk(string val) : publication(),sales() {
		disk_type = val;
	}

	disk(string title, int price, string val) :publication(title, price) ,sales(){
		disk_type = val;
	}

	void putData() {
		cin.ignore();
		cout << "Please enter title of disk:" << endl;
		getline(cin, this->title);

		cout << "Please enter price of disk:" << endl;
		cin >> this->price;

		cout << "Please enter disk type which is either CD or DVD:" << endl;
		cin >> this->disk_type;

		sales::putData();
	}

	void getData() {
		cout << "Title of disk is: ";
		cout << this->title;
		cout << endl;

		cout << "Price of disk is: ";
		cout << this->price;
		cout << endl;

		cout << "Disk type is: ";
		cout << this->disk_type;
		cout << endl;

		sales::getData();
	}
};
int main() {

	disk obj1;
	obj1.putData();
	obj1.getData();

	system("pause");
	return 0;
}