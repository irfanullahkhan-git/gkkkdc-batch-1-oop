#include<iostream>
using namespace std;

class Student{
	public:
		int rollNumber;
		string name;
		int *marks;
		
		Student(string n, int r){
			name = n;
			rollNumber = r;
		}
		// Destructor
		~Student(){
			cout<<"Object with name: "<<name<<" and Roll Number: "<<rollNumber<<" is destroyed\n";	
		}
		
		void printDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
};


int main(){
	Student s1("Ali", 20); 
	s1.printDetails();

	Student s2("Aslam", 22); 
	s2.printDetails();
	
	cout<<"\nMain function ends here\n";	
}
