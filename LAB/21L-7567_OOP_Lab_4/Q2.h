
const int size_array = 20;
const int size_address = 50;

class Student {
	char* roll_no = new char[size_array];
	char* name = new char[size_array];
	char* cnic = new char[size_array];
	char* degree = new char[size_array];
	char* address = new char[size_address];
	
	
	
public:
	Student();
	Student(char* roll_no_arg, char* name_arg, char* cnic_arg, char* degree_arg, char* address_arg);
	Student(char* roll_no_arg, char* name_arg, char* cnic_arg);
	void set_roll_no(char* roll_no_arg);
	void set_name(char* name_arg);
	void set_cnic(char* cnic_arg);
	void set_degree(char* degree_arg);
	void set_address(char* address_arg);
	char* get_roll_no();
	char* get_name();
	char* get_cnic();
	char* get_degree();
	char* get_address();

	void Display();

	~Student();
};
