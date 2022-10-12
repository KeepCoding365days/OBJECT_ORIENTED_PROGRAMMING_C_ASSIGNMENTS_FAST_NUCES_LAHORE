#include <iostream>
using namespace std;
void myTokenizer(char * data, char **list_tokens,char delimiter);
int main(){
	char * data= new char[100];
	char **list_tokens;
	char delimiter;
	int counter=0;
	cout<<"Please enter a sentence:"<<endl;
	cin.getline(data,100);
	cout<<"Please enter a delimeter:"<<endl;
	cin>>delimiter;
	myTokenizer(data,list_tokens,delimiter);
	
	for(int i=0;data[i]!='\0';i++){
		if(data[i]==delimiter){
			counter++;
		}
	}
	counter=counter+1;
	
	delete []data;
	
	for(int i=0; i<counter;i++){
		delete [] list_tokens[i];
	}
	delete [] list_tokens;
	
}
void myTokenizer(char * data, char **list_tokens,char delimiter){
	int counter_token=0,counter=0,prev=0;
	
	for(int i=0;data[i]!='\0';i++){
		if(data[i]==delimiter){
			counter_token++;
		}
	}
	list_tokens=new char * [counter_token+1];
	counter_token=0;
	prev=0;
	for(int i=0;data[i]!='\0';i++){ //ali,is,a,good 3 list_token[0]new char[3] prfev=4 i=6 counter=2,
		counter=0;
		if(data[i]==delimiter){
			counter=i-prev;
			list_tokens[counter_token]=new char[counter];
			for(int j=prev,k=0;j<i;j++){
				list_tokens[counter_token][k]=data[j];
				list_tokens[counter_token][k+1]='\0';
				k++;
			}
			prev=i+1;
			counter_token++;
		}
		if(data[i+1]=='\0'){
			for(int j=i;data[j]!=delimiter;j--){
				prev=j;
				counter++;
			}
			list_tokens[counter_token]=new char[counter];
			for(int j=prev,k=0;data[j]!='\0';j++){
				list_tokens[counter_token][k]=data[j];
				k++;
			}
		}
	}
	
	cout<<"Following are tokens:"<<endl;
	for(int i=0;i<=counter_token;i++){
		for(int j=0;list_tokens[i][j]!='\0';j++){
			cout<<list_tokens[i][j];
		}
		cout<<endl;
	}
}
