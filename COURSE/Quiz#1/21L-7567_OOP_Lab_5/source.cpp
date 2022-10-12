#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static int StringLenght( char* str )
	{
		static int counter=0;
		for(int i=0;str[i]!='\0';i++){
			counter++;
		}
		return counter;
		
	}
	static void StringCopy(char*& dest, char*& src){
//Deep Copies src into dest.
		for(int i=0;src[i]!='\0';i++){
			dest[i]=src[i];
			dest[i+1]='\0';
		}
	}
	static char* GetStringFromBuffer(char* str)
	{
		//Write Yourself
		//This function should allocate required memory on heap, 
		//copy string in this memory using StringCopy and return newly created cstring.
		int counter=0;
		for(int i=0;str[i]!='\0';i++){
			counter++;
		}
		
		char* buffer= new char[counter+1];
		StringCopy(buffer,str);
		return buffer;
	}
};

class Car
{
private:
	static int totalCars;	// initialize it to zero yourself
	int model=0;	
	char* make=0;
	char* color=0;
	char* name=0;
	
public:

	Car()
	{
		model =0;
		color=0;
		make =0;
		name = 0;
		totalCars++;
	}
	//Write Getter of totalCars yourself
	static int GetTotalCars(){
		return totalCars;
	}
	
	void ReadDataFromFile(ifstream& fin)
	{
		char temp[20];
		char name_temp[20];
		char color_temp[20];

		fin>>model;
		fin>>temp;
		
		
		//This is how we call static functions without object		
		make = Helper::GetStringFromBuffer(temp);
		fin>>name_temp;
		
		fin>>color_temp;
		color=Helper::GetStringFromBuffer(color_temp);
		name=Helper::GetStringFromBuffer(name_temp);
		
		//Set rest of the values yourself.
	}
	void PrintListView()
	{
		cout<<model<<"\t";
		for(int i=0;make[i]!='\0';i++){
			cout<<make[i];
		}
		
		cout<<"\t";
		
		for(int i=0;name[i]!='\0';i++){
			cout<<name[i];
		}
		cout<<"\t";
		
		
		for(int i=0;color[i]!='\0';i++){
			cout<<color[i];
		}
		cout<<endl;
	}
	void PrintDetailView()
	{	
	 	cout<<"Model: "<<model;
	 	cout<<endl;
	 	cout<<"Make: ";
	 	for(int i=0;make[i]!='\0';i++){
	 		cout<<make[i];
		 }
		cout<<endl;
		
		cout<<"Name: ";
	 	for(int i=0;name[i]!='\0';i++){
	 		cout<<name[i];
		 }
		cout<<endl;
		
		cout<<"Color: ";
	 	for(int i=0;color[i]!='\0';i++){
	 		cout<<color[i];
		 }
		cout<<endl;
		//Write yourself
	}
	
	void Input()
	{		
		//Do not consume one extra byte on heap
		//Use only one temp buffer
		char temp[20];
		cout<<"Please enter car model:"<<endl;
		cin>>model;
		
		cout<<"Please enter car name:"<<endl;
		cin.ignore();
		cin.getline(temp,20);
		
		
		name=Helper::GetStringFromBuffer(temp);
		
		cout<<"Please enter car color:"<<endl;
		cin.getline(temp,20);
		
		
		color=Helper::GetStringFromBuffer(temp);
		
		cout<<"Pleae enter car make:"<<endl;
		cin.getline(temp,20);
		
		make=Helper::GetStringFromBuffer(temp);
		
	}
	~Car()
	{		
		
		cout << "Destroying ";
		PrintListView();
		delete  []color;
		delete  []name;
		delete  []make;
		totalCars--;
		
		//
		//Deallocate memory yourself
	}

};

Car* ReadDataFromFile()
{
	ifstream fin;
	int totalCars = 0;
	char buffer[80];

	fin.open("CarsData.txt");
	if (fin.is_open())
	{
		fin >> totalCars;
		//cout << totalCars;
		fin.getline(buffer, 80, '\n');	//We are not saving comment
		//cout << buffer << endl;

		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!fin.eof())
		{
			
			carsList[i].ReadDataFromFile(fin);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}

int Car::totalCars=0;

int main()
{
	//Comment all the code. Then uncomment it line by line. 
	//Implement/add functionality for uncommented line. 
	//Execute and verify result with output.
	Car* carsList = ReadDataFromFile();
	int count = 0;
	
	if (carsList != 0)
	{
		
		count = Car::GetTotalCars();	//Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;
		
		//Test one Print at a time.
/**	cout << "\nCars List:\n\n";
		{
			for (int i = 1; i < count ; i++)
			{				
				carsList[i].PrintListView();
			}			
}
}**/		//Comment above printing and Test Printing 2
		cout << "\nCars List:\n\n";
		{
		//	Car temp = carsList[0];
			
		//	temp.PrintListView();				//made a few changes in main, it was deleting object when assigned to temp. therefore deletion of array was not possible. 
			
			for ( int i = 0; i < count ; i++)
			{				
				//temp=carsList[i];
				carsList[i].PrintListView();
				//temp.PrintListView();
			}			
		
		if(carsList)
			delete[] carsList;
}

	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl << endl;
}
	Car testCar;	
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();
	
	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl << endl << endl;
	
	system("pause");
	return 0;
}


