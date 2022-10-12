#include <iostream>
using namespace std;
class myString{
	char *str;
	int length;
	public:
		myString();
		myString(const char *);
		myString(const myString&);
		int getLength();
		void operator ++(int);
		friend ostream & operator <<(ostream &out ,const myString &obj);
		friend istream & operator >>(istream &in ,myString &obj);
		void operator =(const myString obj);
		char& operator [](int idx);
		bool operator ==(const myString obj);
		void Display(){
			for(int i=0; str[i]!='\0';i++){
				cout<<str[i];
			}
		}
		~myString();
		
	
};

myString::myString(){
	length=0;
}

myString::myString(const char * data){
	int len=0;
	
	for(int i=0;*(data+i)!='\0';i++){
		len++;
	}
	
	str=new char[len+1];
	for(int i=0;*(data+i)!='\0';i++){
		*(str+i)=*(data+i);
		*(str+i+1)='\0';
	}
	length=len;
}

myString::myString(const myString & string){
	str=string.str;
	length=string.length;
}

int myString::getLength(){
	return length;
}

void myString::operator ++(int){
			char *ptr=str;
			for(int i=0;ptr[i]!='\0';i++){
				if(int(ptr[i]>=97)){
					ptr[i]-=32;
				}
			}
		}

void myString::operator =(const myString obj){      
	length=obj.length;
	char arr[length];
	for(int i=0;obj.str[i]!='\0';i++){
		str[i]=obj.str[i];
		str[i+1]='\0';
	}
}	


char & myString::operator [](int idx){
	if(idx>=length){
		cout<<"Wrong input";
		exit(0);
	}
	else{
	char *ptr=&str[idx];
	return str[idx];
}
}

bool myString::operator ==(const myString obj){
	bool check=1;
	if(length!=obj.length){
		check=0;
		return check;
	}
	else{
		for(int i=0;i<length;i++){
			if(str[i]!=obj.str[i]){
				check=0;
				return check;
			}
		}
	}
}

myString::~myString(){
	cout<<"Deleting";
}

ostream & operator <<(ostream &out ,const myString &obj){
	
	for(int i=0;obj.str[i]!='\0';i++){
		out<<obj.str[i];
	}
	return out;
}

istream & operator >>(istream &in ,myString &obj){
	char *data=new char [50];
	cin.getline(data,50);
	int len=0;
	for(int i=0;*(data+i)!='\0';i++){
		len++;
	}
	
	obj.str=new char[len+1];
	for(int i=0;*(data+i)!='\0';i++){
		obj.str[i]=*(data+i);
		obj.str[i+1]='\0';
	}
	obj.length=len;
	return in;
}


int main(){
	cout<<"Please enter a string:"<<endl;
	
	myString word;
	cin>>word;
	myString word_2;
	word_2=word;
	word_2++;
	word[0]='A';
	cout<<word;
	cout<<endl;
	cout<<word_2;
	cout<<endl;
	if(word_2==word){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	 //mam I have overloaded '==', '=' operators, now whenever I call these methods it call destructor 
	 //itself before exiting function for left operand. Please let me know how I can avoid that. I shall be very thankful
	return 0;
}


