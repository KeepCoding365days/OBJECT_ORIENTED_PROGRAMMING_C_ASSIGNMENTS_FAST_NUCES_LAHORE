#include <iostream>
using namespace std;
int main(){
	char*ptr=new char [100];
	int freq[6]={0};
	int temp_int=0;
	char temp_char=0;
	char vowel[5]={'A','E','I','O','U'};
	cout<<"Please enter string:"<<endl;
	cin.getline(ptr,100);//memory wastage
	
	for(int i=0;ptr[i]!='\0';i++){
		if(ptr[i]=='A'||ptr[i]=='a'){
			freq[0]++;
		}
		else if(ptr[i]=='E'|| ptr[i]=='e'){
			freq[1]++;
		}
		else if(ptr[i]=='I'|| ptr[i]=='i'){
			freq[2]++;
		}
		else if(ptr[i]=='O'|| ptr[i]=='o'){
			freq[3]++;
		}
		else if(ptr[i]=='U'|| ptr[i]=='u'){
			freq[4]++;
		}
		else if((int(ptr[i])>=65 && int(ptr[i])<=90 )|| (int(ptr[i])>=97 && int(ptr[i])<=122)){
			freq[5]++;
		}
	}
	cout<<"Total consonants are: "<<freq[5]<<endl;
	cout<<"Total vowels are: "<<freq[0]+freq[1]+freq[2]+freq[3]+freq[4]<<endl;
	
	for(int i=0;i<5;i++){	//sorting arrays used two arrays to sort
		for(int j=i;j<5;j++){
			if(freq[i]<freq[j]){
				temp_int=freq[i];
				freq[i]=freq[j];
				freq[j]=temp_int;
				temp_char=vowel[i];
				vowel[i]=vowel[j];
				vowel[j]=temp_char;
				
			}
		}
	}
	cout<<"Total number of "<<vowel[0]<< " is "<<freq[0]<<endl;
	cout<<"Total number of " <<vowel[1]<<" is "<<freq[1]<<endl;
	cout<<"Total number of "<<vowel[2]<<" is "<<freq[2]<<endl;
	cout<<"Total number of "<<vowel[3]<<" is "<<freq[3]<<endl;
	cout<<"Total number of "<<vowel[4]<<" is "<<freq[4]<<endl;
	
	delete []ptr;
	system ("pause");
	return 0;
}
