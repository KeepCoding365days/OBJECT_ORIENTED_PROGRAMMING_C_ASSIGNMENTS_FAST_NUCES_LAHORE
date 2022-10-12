//program to take file and check super angrams and imperfect palindromes. I have also submited a file so it may be easy while checking.
#include<iostream>
#include<fstream>
using namespace std;


bool super(char[20],char[20]);  //for super angrams
bool imperfect_palindrome(char[20]); //for imperfect palindromes
int freq(char[20],int);	//to check frequency

int main(){
	
	char word_1[20];//for inputs
	char word_2[20];
	char path[150];	//for file path
	strt:
	cout<<"Enter a file to check Super Angrams and imperefect Palindroms.File must not contain words of more than 20 letters.\nPlease enter file path:"<<endl;
	cin.getline(path,150);
	
	ifstream input(path);
	if(!input){
		cout<<"File does not exist."<<endl;
		
		goto strt;
	}
	
	while(!input.eof()){
		
	input>>word_1>>word_2;
	
	if(imperfect_palindrome(word_1)){			//checking for imperfect palindromes using function
		cout<<"yes ";
	}
	else{
		cout<<"no ";
	}
	
	if(imperfect_palindrome(word_2)){
		cout<<"yes ";
	}
	else{
		cout<<"no ";
	}
	
	
	if(super(word_1,word_2)){				//checking for super angrams using function
	cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
}
	input.close();
	
	system("pause");
	return 0;
}

bool super(  char word_1[20],char word_2[20]){
	int freq_1=0,freq_2=0,freq_diff=0;		//to calc freq difference
	
	bool check=0,done=0;  /*check is for super angram and done is to not use a previously 
	used number again while calculating frequency difference*/
	
	for(int i=0;word_1[i]!='\0';i++){			//checking if both words have same letters
		check=0;
		for(int j=0;word_2[j]!='\0';j++){
			if(word_1[i]==word_2[j]){
				check=1;
				break;
			}
		}
		if(check==false)
			break;
}

if(check==false){
	return check;
}
	for(int i=0;word_2[i]!='\0';i++){
		check=0;
		for(int j=0;word_1[j]!='\0';j++){
			if(word_1[j]==word_2[i]){
				check=1;
				break;
			} 
				
		}
		if(check==false)
			break;
}	
if(check==false){
	return check;
}
//checking frequency difference
for(int i=0;word_1[i]!='\0';i++){		//stakes takes
    done=0;
		for(int k=i-1;k>=0;k--){
			if (word_1[k]==word_1[i]){		// to not use previously used word again
				done=1;
			}
			if(done==true){
			break;
			}
		}
	for(int j=0;word_2[j]!='\0';j++){

		if(word_1[i]==word_2[j]&& done==0){
			freq_1=freq(word_1,i);
			freq_2=freq(word_2,j);
			if(freq_1>freq_2){
				freq_diff+=(freq_1-freq_2);
			}
			else{
				freq_diff+=(freq_2-freq_1);
			}
			break;
		}
	}
}	
	if(freq_diff>2){
		check=0;
	}

	return check;
}
int freq(char arr[20],int idx){
	int frequency=1;
	for(int i=0;arr[i]!='\0';i++){
		if (i!=idx &&arr[i]==arr[idx]){
			frequency++;
		}
	}
	
	return frequency;
}
bool imperfect_palindrome(char arr[20]){  //imperfect palindrome
	int count=0,diff=0;
	bool check=1; 
	
	for(int i=0;arr[i]!='\0';i++){		//to calclate size
		count++;
	}   
	for(int i=0;i<count;i++){		//calclating diff while reading forward and backward
		for(int j=count-1-i;j>=0;j--){
			if(arr[i]!=arr[j]){
				diff++;
			}
			break;
		}
	}
	if(diff==0 || diff>2){
		check=0;
	}
	return(check);
}
