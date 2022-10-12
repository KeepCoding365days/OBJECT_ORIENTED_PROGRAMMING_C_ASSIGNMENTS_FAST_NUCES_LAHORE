#include <iostream>
using namespace std;
class NLP {
	char* ptr = new char[100];//not iNITIALIZE HERE
public:
	NLP() {
	}
	NLP(char* ptr1) {
		for (int i = 0;ptr1[i] != '\0';i++) {
			*(ptr + i) = *(ptr1 + i);
			*(ptr + i + 1) = '\0';
		}
	}
	void set_data(char* ptr1) {
		for (int i = 0;ptr1[i] != '\0';i++) {
			*(ptr + i) = *(ptr1 + i);
			*(ptr + i + 1) = '\0';
		}
	}

	char* get_data() {
		return ptr;
	}
	int wordCount() {
		int size = 0;
		for (int i = 0;ptr[i] != '\0';i++) {
			if (ptr[i] == ' ') {
				size++;
			}
		}
		size++;
		return size;
	}

	int str_length() {
		int length = 0;
		for (int i = 0; ptr[i] != '\0';i++) {
			if (ptr[i] != ' ') {
				length++;
			}
		}
		return length;
	}
	int unique() {
		int len = 0, strt = 0, next = 0, k = 0, j = 0, prev = 0, counter = 0;
		bool check = 1;
		for (int i = 0;ptr[i] != '\0';i++) {
			
			if (ptr[i] == ' ') { 
				counter++;
				next = 0;//ali is ali good boy ali ali ali ali ali ali
				k = i + next + 1;
				check = 0;
				
				while (ptr[k] != '\0') {
					
					if (counter == 1) {
						j = 0;
					}
					else {
						j = prev + 1;
					}
					for (k = i + next + 1; ptr[k] != ' ' && ptr[k] != '\0';k++) {//k=3+0+1
					check=0;
						if ((ptr[j] != ptr[k]&&ptr[k]!='.')||(ptr[j-1]!=ptr[k-1] &&ptr[j-1]!=' '&&ptr[k-1]!='0')|| j!=i-1) {
							check = 1;
						}
						
						next = k - i + 1; //5-3=2
						j++;//j=1
					}
					if(!check){
						break;
					}
				}
				
				prev = i;
				if (check) {
					len++;//++
				}
			}
			
		}
		len++;
		
		return len;
	}
	void uniGram(){
		int len = 0, strt = 0, next = 0, k = 0, j = 0, prev = 0, counter = 0,check_counter=0,running=0,temp_int=0,space_check=0;
		int k_reverse=0, j_reverse=0, prev_reverse=0;
		bool check = 1;
		char unique[100];
		char temp[100];
		char temp_1[100];
		int freq[20]={0};
		
		for (int i = 0;ptr[i] != '\0';i++) {	//looping over the string
			
			if (ptr[i] == ' ') { //seprating words
				counter++;
				next = 0;//is ali is a
				k = i + next + 1;//k=3,j=0
				check = 0;
				
				while (ptr[k] != '\0') {
					
					if (counter == 1) {
						j = 0;
					}
					else {
						j = prev + 1;
					}
					for (k = i + next + 1; ptr[k] != ' ' && ptr[k] != '\0';k++) {//k=3+0+1 an in  k=3,4,
					check=0;
						if ((ptr[j] != ptr[k]&&ptr[k]!='.')||(ptr[j-1]!=ptr[k-1] && ptr[j-1]!=' ' &&ptr[k-1]!=' ' )||j!=i-1) {
							check = 1;
							//ali a
						}
						
						
						next = k - i + 1; //5-3=2
						j++;//j=1
					}
					
					if(check==0){
						break;
					}
				}
				
				
				
				if (check) {
					check_counter++;
					if(check_counter>1){
						strt++;
					}
					if(counter==1){
						next=0;
					}
					else{
						next=prev+1;
					}
					for(int m=next;m<i;m++){//creating a seprate array of unique numbers
						unique[strt]=ptr[m];
						unique[strt+1]=' ';
						unique[strt+2]='\0';
						strt++;
					}
					freq[check_counter-1]=1;
					//freq[check_counter]=1;
					running=0;
					prev_reverse=prev;
					k_reverse=prev_reverse-1;
					while (k_reverse>=0) { //making an array of frequencies
					running++;
					j_reverse=i-1;
					for (k_reverse = prev_reverse-1; ptr[k_reverse] != ' ' && k_reverse>=0&&ptr[j_reverse]!=' ';k_reverse--) { //boy is boy a k=5,2 j=9 //1 2 //
					
					check=0;
						if (ptr[j_reverse] != ptr[k_reverse] ||(ptr[j_reverse+1]!=ptr[k_reverse+1]&& ptr[k_reverse+1]!=' '&& ptr[j_reverse+1]!=' ') ||(ptr[j_reverse-1]!=ptr[k_reverse-1]&& ptr[k_reverse-1]!=' '&& ptr[j_reverse-1]!=' ')) {
							check = 1;
						}
						j_reverse--;
						
					}
					
					if(running==counter-1){
						k_reverse=-1;
					}
					if (check==0){
						
						freq[check_counter-1]++;
					}
					prev_reverse=k_reverse;
				}
					
				}
				prev=i;
			}
			if(counter>0){
				unique[strt+2]=' ';
			}
			
			freq[check_counter]=1;
			if(ptr[i+1]=='\0'){
				k = prev-1;
				check = 0;
				j=i;
				while (k>=0) {
					j=i;
					for (k = prev-1; ptr[k] != ' ' && k>=0&&ptr[j]!=' ';k--) {
					
					check=0;
						if (ptr[j] != ptr[k] ||(ptr[j+1]!=ptr[k+1] && ptr[j+1]!=' '&&ptr[k+1]!=' ')) {
							check = 1; //ali ali
						}
						j--;
					}
					if (check==0){
						freq[check_counter]++;
					}
					prev=k;
				}
				
					for(int m=i;ptr[m]!=' ';m--){
						next=m;
				}
					if(check_counter>=1){
					next--;
				}
					for(int m=next;ptr[m]!='\0';m++){
						unique[strt]=ptr[m];
						unique[strt+1]=' ';
						unique[strt+2]='\0';
						strt++;
					}
				
			}
		}
		
		
		
		len=0;
		cout<<"Unigrams are:"<<endl;
		for(int l=0;unique[l]!='\0';l++){
			cout<<unique[l];
			if(unique[l]==' '){
				cout<<": "<<freq[len]<<endl;
				len++;
			}
		}
		
	
	}
	void biGram(){
		int len = 0, strt = 0, next = 0, k = 0, j = 0, prev = 0, counter = 0,space_counter=0,running=0,temp_int;
		int k_reverse=0, j_reverse=0, prev_reverse=0;
		bool check = 1;
		char unique[20][100];
		int freq[20]={0};
		char temp[100];
		
		for(int i=0;ptr[i]!='\0';i++){
			if(ptr[i]==' '||ptr[i+1]=='\0'){
				space_counter++;
			}
			if(ptr[i+1]=='\0'){
				i++;
			}
			if(space_counter==2){
				if(counter>0){
				check=0; 
			}
				
					for(int l=0;l<counter;l++){//is a is a counter=6/prev=22, n=
						check=0;
						for(int n=0,k=i-1;unique[l][n]!='\0';n++){
							if(unique[l][n]!=ptr[prev+n]){   
								check=1;
							}
							k--;
						}
						
						if(check==0){
							freq[l]++;
							break;
						}
					}
				
					
					if(check){
					for(int j=prev,m=0;j<i;j++){
					unique[counter][m]=*(ptr+j);			//ali is a good boy and is a bad boy
					unique[counter][m+1]='\0';		//	ali is ,is a,a good, good boy,boy and,and a, a bad, bad boy
					m++;
				}
				freq[counter]=1;
				counter++;
				}
				space_counter=1;
				
			for(int k=i-1;ptr[k]!=' ';k--){
				prev=k;
			}	
			}
			
		}
		for(int i=0;i<counter;i++){ 	//sorting
			for(int j=i;j<counter;j++){
				if(freq[i]<freq[j]){
					temp_int=freq[i];
					freq[i]=freq[j];
					freq[j]=temp_int;
					
					for(int k=0;unique[i][k]!='\0';k++){
						temp[k]=unique[i][k];
						temp[k+1]='\0';
					}
					
					for(int k=0;unique[j][k]!='\0';k++){
						unique[i][k]=unique[j][k];
						unique[i][k+1]='\0';
					}
					
					for(int k=0;temp[k]!='\0';k++){
						unique[j][k]=temp[k];
						unique[j][k+1]='\0';
					}					
					
				}
			}
		}
	cout<<"Bigrams are:"<<endl;
		for(int i=0;i<counter;i++){
		for(int j=0;unique[i][j]!='\0';j++){
			cout<<unique[i][j];
		}	
		cout<<" : "<<freq[i]<<endl;
		
	}  
	}
	void triGram(){
		int len = 0, strt = 0, next = 0, k = 0, j = 0, prev = 0, counter = 0,space_counter=0,running=0,space_check=0,temp_int=0;
		bool check = 1;
		char unique[20][100];
		int freq[20]={0};
		char temp[100];
		
		for(int i=0;ptr[i]!='\0';i++){
			if(ptr[i]==' '||ptr[i+1]=='\0'){
				space_counter++;
			}
			if(ptr[i+1]=='\0'){
				i++;
			}
			if(space_counter==3){
				if(counter>0){
				check=0; 
			}
				
					for(int l=0;l<counter;l++){//is a is a counter=6/prev=22, n=
						check=0;
						for(int n=0,k=i-1;unique[l][n]!='\0';n++){
							if(unique[l][n]!=ptr[prev+n]){   
								check=1;
							}
							k--;
						}
						
						if(check==0){
							freq[l]++;
							break;
						}
					}
				
					
					if(check){
					for(int j=prev,m=0;j<i;j++){
					unique[counter][m]=*(ptr+j);			//ali is a good boy and is a bad boy
					unique[counter][m+1]='\0';		//	ali is ,is a,a good, good boy,boy and,and a, a bad, bad boy
					m++;
				}
				freq[counter]=1;
				counter++;
				}
				space_counter=2;
			space_check=0;	
			for(int k=i-1;space_check<=1;k--){
				if(ptr[k]==' '){
					space_check++;
				}
				prev=k+1;
			}	
			}
		}
		
				for(int i=0;i<counter;i++){ 	//sorting
			for(int j=i;j<counter;j++){
				if(freq[i]<freq[j]){
					temp_int=freq[i];
					freq[i]=freq[j];
					freq[j]=temp_int;
					
					for(int k=0;unique[i][k]!='\0';k++){
						temp[k]=unique[i][k];
						temp[k+1]='\0';
					}
					
					for(int k=0;unique[j][k]!='\0';k++){
						unique[i][k]=unique[j][k];
						unique[i][k+1]='\0';
					}
					
					for(int k=0;temp[k]!='\0';k++){
						unique[j][k]=temp[k];
						unique[j][k+1]='\0';
					}					
					
				}
			}
		}
		
		
	cout<<"Trigrams are:"<<endl;
		for(int i=0;i<counter;i++){
		for(int j=0;unique[i][j]!='\0';j++){
			cout<<unique[i][j];
		}	
		cout<<" : "<<freq[i]<<endl;
		
	}
	}
	~NLP() {
		delete[]ptr;
	}
};
int main() {
	char* ptr = new char[100]; //is a a is a is again
	cout<<"Please enter a sentence:"<<endl;
	cin.getline(ptr, 100);
	NLP sentence;
	sentence.set_data(ptr);
	cout<<"Following is sentence:"<<endl;
	char* ptr1 = sentence.get_data();
	for (int i = 0;ptr1[i] != '\0';i++) {
		cout << ptr[i];
	}
	cout << endl;
	cout<<"Number of words is:"<<endl;
	cout << sentence.wordCount();
	cout << endl;

	cout<<"String length is:"<<endl;
	cout << sentence.str_length();
	cout << endl;

	cout<<"Number of Unique words is:"<<endl;
	cout << sentence.unique();
	cout << endl;
	sentence.uniGram();
	cout<<endl;
	
	sentence.biGram();
	cout<<endl;
	
	sentence.triGram();
	
	delete[]ptr;
	delete[]ptr1;


	system("pause");
	return 0;
}
