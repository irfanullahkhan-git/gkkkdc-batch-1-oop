#include<iostream>
using namespace std;

class Student{
	public:
		int rollNumber;
		string name;
		// Constructor: 
		// Same name as class
		// No return type
		// Automatically called when object is created.
		
		// Types of Constructor
		// 1. Default Constructor
		// 2. Parameterized Constructor
		// 3. Copy Constructor
		//	 - First param of constructor must be reference to an object of the same class
		
		
		// 1. Default Constructor
		Student(){
			rollNumber = 0;
			name = "Not Set";	
		}
		
		// 2. Parameterized Constructor
		Student(string n, int r){
			name = n;
			rollNumber = r;
		}
		
		Student(int roll_no, string temp_name){
			name = temp_name;
			rollNumber = roll_no;
		}
		
		// 3. Copy Constructor
		Student(Student &ref){
			name = ref.name;
			rollNumber = ref.rollNumber;
		}
		
		void printDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
};


int main(){
	Student s1; // Default Const
	s1.printDetails();
	
	s1.name = "Ali";
	s1.rollNumber = 20;
	s1.printDetails();
	
	Student s2("Aslam", 22); // Param Cons (string, int)
	s2.printDetails();	
	
	Student s3(30, "Ayaz"); // Param Cons (int, string)
	s3.printDetails();	
	
	Student s4 = s1;
	s4.rollNumber = 31;
	s4.printDetails();
}
