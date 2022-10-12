#include <iostream>
using namespace std;
class DB;
class DM{
	int m, cm;
	public:
		DM();
		DM(int,int);
		friend DB add(DB,DM);
		void Display();
};
class DB{
	int foot, inch;
	public:
		DB();
		DB(int,int);
		friend DB add(DB,DM);
		void Display();
};
DM::DM(){
	m=0;
	cm=0;
}
DM::DM(int m,int cm){
	this->m=m;
	this->cm=cm;
}

void DM::Display(){
	cout<<m<<" m "<<cm<<" cm"<<endl;
}
DB::DB(){
	foot=0;
	inch=0;
}
DB::DB(int foot,int inch){
	this->foot=foot;
	this->inch=inch;
}


void DB::Display(){
	cout<<foot<<" feet "<<inch<<" inches"<<endl;
}

DB add(DB obj1,DM obj2){
	DB add;
	add.foot=obj1.foot+(obj2.m*3.28);
	add.inch=obj1.inch+(obj2.cm/2.54);
	return add;
}

int main(){
	DB obj_1(2,4);
	DM obj_2(4,3);
	DB added;
	added=add(obj_1,obj_2);
	added.Display();


	return 0;
}
