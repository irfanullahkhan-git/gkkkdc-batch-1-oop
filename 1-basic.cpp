#include<iostream>
using namespace std;

class Student{
	public:
	// Data Members
	int rollNumber;
	string name;
	
	// Member functions
	void printDetails(){
		cout<<"Name: "<<name<<endl;
		cout<<"Roll Number: "<<rollNumber<<endl;
	}
	
};




int main(){
	Student s1;	
	s1.name = "Ali";
	s1.rollNumber = 20;
	s1.printDetails();
	
//	cout<<"Name: "<<s1.name<<"\n";
//	cout<<"Roll No: "<<s1.rollNumber<<endl;
	
	Student s2;
	s2.name = "Aslam";
	s2.rollNumber = 22;
	s2.printDetails();
//	cout<<"Name: "<<s2.name<<endl;
//	cout<<"Roll No:"<<s2.rollNumber;


}
