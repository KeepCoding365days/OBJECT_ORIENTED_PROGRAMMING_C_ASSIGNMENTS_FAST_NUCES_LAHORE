#include <iostream>
using namespace std;

struct ComplexNum{
	int real;
	int imaginary;
};
class Calculator{
public:
	virtual void add() = 0;
	virtual void subtract() = 0;
	virtual void multiply() = 0;
	virtual void divide() = 0;
};
class SimpleNumber : public Calculator{
private:
	int a; 
	int b;
public:
	SimpleNumber(){
		a = 0;
		b = 0;
	}
	SimpleNumber(int a_1, int b_1){
		a = a_1;
		b = b_1;
	}
	void add(){
		cout << "After addition is " << a + b << endl;
	}
	void subtract(){
		cout << "After subtraction is " << a - b << endl;

	}
	void multiply(){
		cout << "After multiplication is " << a * b << endl;
	}
	void divide(){
		cout << "After division is " << a / b << endl;
	}

};

class ComplexNumber : public Calculator{
private:
	ComplexNum a;
	ComplexNum b;
public:

	ComplexNumber(){
		a.real = 0;
		a.imaginary = 0;
		b.real = 0;
		b.imaginary = 0;
		
	}

	ComplexNumber(int a1, int b1){
		a.real = a1;
		a.imaginary = 0;
		b.real = b1;
		b.imaginary = 0;

	}

	ComplexNumber(int a1, int b1, int c1, int d1){
		a.real = a1;
		a.imaginary = b1;
		b.real = c1;
		b.imaginary = d1;

	}
	
	void add(){
		cout << "After addition: Real is " << a.real +b.real  <<" Imaginary is: "<<a.imaginary+ b.imaginary<< endl;
	}
	void subtract(){
		cout << "After subtraction: Real is " << a.real - b.real << " Imaginary is: " << a.imaginary - b.imaginary << endl;

	}
	void multiply(){
		cout << "After subtraction: Real is " << (a.real*b.real) - (b.imaginary*a.imaginary) << " Imaginary is: " << (a.imaginary*b.real) + (b.imaginary*a.real) << endl;
	}
	void divide(){
		cout << "After Division: Real is " << ((a.real*b.real) + (b.imaginary*a.imaginary)) / ((b.real*b.real) + (b.imaginary*b.imaginary)) << " Imaginary is: " << ((a.imaginary*b.real) - (b.imaginary*a.real)) / ((b.real*b.real) + (b.imaginary*b.imaginary) )<< endl;
	}

};
int main(){
	Calculator **ptrs = new Calculator*[2];
	ptrs[0] = new SimpleNumber(6, 7);
	ptrs[1] = new ComplexNumber(6, 2, 8, 4);

	ptrs[0]->add();
	ptrs[0]->subtract();
	ptrs[0]->multiply();
	ptrs[0]->divide();

	ptrs[1]->add();
	ptrs[1]->subtract();
	ptrs[1]->multiply();
	ptrs[1]->divide();

	delete ptrs[0];
	delete ptrs[1];

	delete[] ptrs;

	system("pause");
	return 0;
}