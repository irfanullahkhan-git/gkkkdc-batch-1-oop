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
		
		Student(){
			rollNumber = 0;
			name = "Not Set";	
		}
		
		void printDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
};


int main(){
	Student s1;
	cout<<"Before setting details"<<endl;
	s1.printDetails();
	
	s1.name = "Ali";
	s1.rollNumber = 20;
	cout<<"After setting details"<<endl;
	
	s1.printDetails();
	
	Student s2;
	s2.name = "Aslam";
	s2.rollNumber = 22;
	s2.printDetails();
}
