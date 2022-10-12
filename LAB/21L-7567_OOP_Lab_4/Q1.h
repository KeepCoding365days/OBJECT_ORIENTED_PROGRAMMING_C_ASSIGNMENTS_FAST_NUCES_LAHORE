const int size_name = 31;
const int size_dept = 41;
class Employee{
	int id;
	char * name = new char[size_name];
	char * Dept = new char[size_dept];

public:
	Employee();
	Employee(int id_arg, char* name_arg, char*dept_name_arg);
	
	
	Employee(int id_arg, char* name_arg);
	void set_id(int id_arg);
	
	
	void set_name(char * name_arg);
	void set_dept(char * dept_name_arg);
	int get_id();
	char* get_name();
	
	char* get_dept_name();
	void Display();
	~Employee();
};
