#include <string>
#include <iostream>
using namespace std;

class sales{
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
			cin>>this->monthly_sales[i];
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

class book : public publication, public sales {
protected:
	int page_count;

public:
	book() :publication(),sales() {
		page_count = 0;
	}

	book(int val) : publication(), sales() {
		page_count = val;
	}

	book(string title, int price, int val) :publication(title, price) ,sales() {
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

class tape : public publication, public sales {
protected:
	float play_time;

public:
	tape() :publication(),sales(){
		play_time = 0;
	}

	tape(int val) : publication(),sales() {
		play_time = val;
	}

	tape(string title, int price, int val) :publication(title, price),sales() {
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

int main() {
	book obj1;
	obj1.putData();
	obj1.getData();

	tape obj3;
	obj3.putData();
	obj3.getData();

	system("pause");
	return 0;
}
