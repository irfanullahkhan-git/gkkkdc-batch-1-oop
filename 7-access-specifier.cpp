#include<iostream>
using namespace std;

// - Access Specifiers
// - public
// - private

class Student{
	private:
		int rollNumber;
		string name;
		
	public:
		Student(string n, int r){
			setName(n);
			setRollNo(r);
		}

		~Student(){
			cout<<"Object with name: "<<name<<" and Roll Number: "<<rollNumber<<" is destroyed\n";	
		}
		
		void setName(string n){
			if(n== ""){
				cout<<"Error: The given name is invalid.\n";
			}else{
				name = n;
			}
		}
		
		void setRollNo(int r){
			if(r <0){
				cout<<"Error: the given roll number is invalid\n";
			}else{
				rollNumber = r;
			}
		}
		
		int getRollNumber(){
			return rollNumber;
		}
		
		string getName(){
			return name;
		}
		
		void printDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
};



int main(){
	Student s1("", -20); 
	s1.printDetails();

	Student s2("Aslam", 22); 
	s2.printDetails();
	
	cout<<"\nMain function ends here\n";	
}
