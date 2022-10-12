#include <string>
#include <iostream>
using namespace std;

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
		getline(cin,this->title);
	
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

class book : public publication {
protected:
	int page_count;

public:
	book() :publication() {
		page_count = 0;
	}

	book(int val) : publication() {
		page_count = val;
	}

	book(string title, int price, int val) :publication(title, price) {
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

	}
};

class tape : public publication {
protected:
	float play_time;

public:
	tape() :publication() {
		play_time = 0;
	}

	tape(int val) : publication() {
		play_time = val;
	}

	tape(string title, int price, int val) :publication(title, price) {
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

	}

	void getData(){
		cout << "Title of tape is: ";
		cout << this->title;
		cout << endl;

		cout << "Price of tape is: ";
		cout << this->price;
		cout << endl;

		cout << "Play time of tape is: ";
		cout << this->play_time;
		cout << endl;

	}
};

int main() {
	publication obj;
	obj.putData();
	obj.getData();

	book obj1;
	obj1.putData();
	obj1.getData();

	tape obj3;
	obj3.putData();
	obj3.getData();

	system("pause");
	return 0;
}