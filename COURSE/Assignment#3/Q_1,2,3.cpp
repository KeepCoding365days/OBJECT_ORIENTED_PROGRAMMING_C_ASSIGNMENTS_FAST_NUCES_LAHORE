#include <iostream>
using namespace std;

//Q1,2,3
class Time {
	int hours;
	int mins;
	int sec;
 public:
	Time() {
		hours = 0;
		mins = 0;
		sec = 0;
	}
	Time(int val) {
		
		mins = val;
		sec = val;
		if (val > 12) {	//checking hours does not go beyond 12
			while (val % 12 == 0) {
				val -= 12;
				mins=0;
			}
		}
		hours = val;

	}
	Time(int h, int m, int s) {
		if(h>12){
			while(h%12==0){
				h-=12;
				hours = h;
	}
		
	}
	else{
		hours=h;
	}
	if(m>60){
		m=0;
		mins = m;
		if(hours<12){
		
		hours++;
	}
	else{
		hours=1;
	}
}
else{
	mins=m;
}
	if(s>60){
		s=0;
		mins++;
		sec = s;
	}
	else{
	sec=s;
	}
	}
	void Display() {
		cout << hours << ":" << mins << ":" << sec << endl;
	}
	Time operator ++(int val) {
		if (hours == 12) {		//checking so hours go beyond 12
			hours = 1;
		}
		else {
			hours++;
		}
		if(mins==60){
			if(hours==12){
				hours=1;	//checking if mins go above 60, set hours to +1 and mins to 0
			}
			else{
				hours++;
			}
			mins=0;
		}
		else{
		mins++;
	}
	
	if(sec==60){
			if(mins==60){
				mins=0;	//checking if sec go above 60, set mins to +1 and sec to 0
			}
			else{
				mins++;
			}
			sec=0;
		}
		else{
		sec++;
	}
		

		return *this;
	}
	
	Time operator ++() {
		this->operator ++(1);
		return *this;
	}
	
	
	Time operator --(int val) {
		if (hours == 1) { //checking so hours remain b/w 0 to 12
			hours = 12;
		}
		else {
			hours--;
		}
		if(mins==0){	// checking for mins if mins<0 hours-- else mins --
			if(hours==1){
				hours=12;
			}
			else{
				hours--;
			}
			mins=59;
		}
		else{
		mins--;
	}
	
	
	if(sec==0){	// checking for mins if mins<0 hours-- else mins --
			if(mins==0){
				mins=59;
				hours--;
			}
			else{
				mins--;
			}
			sec=59;
		}
		else{
		sec--;
	}
		
		return *this;
	}
	
	Time operator --() {
		this->operator --(0);

		return *this;
	}

	Time operator -(Time obj) { //operator overloading for -
		Time obj_new;

		obj_new.hours = hours - obj.hours;
		obj_new.mins = mins - obj.mins;
		obj_new.sec = sec - obj.sec;
		
		if(obj_new.hours>12){
			obj_new.hours=1;
			obj_new.mins=0;
			obj_new.sec=0;
		}
		else if(obj_new.hours<1){
			obj_new.hours=1;
			obj_new.mins=0;
			obj_new.sec=0;
		}
		return obj_new;

	}

	Time operator *(float num) { //multiplying num with all values and then checking
		if(num<0){
			num=-num;
		}
		hours = hours * num; 
		if(hours>12){
			hours=1;
		}

		mins=mins*num;
		while(mins>=60){
			mins=mins%60;
			hours++;
			
		}
		
		sec = sec * num; //multiplying seconds
		while(sec>=60){
			sec=sec%60;
			mins++;
			
		}

		return *this;
	}
};


int main() {
	Time obj(2,30,0);
	
    obj*3;
	obj.Display();

	system("pause");
	return 0;
}
