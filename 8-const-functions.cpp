#include<iostream>
using namespace std;
// const functions 

class Student{
	private:
		int rollNumber;
		string name;
		
	public:
		Student(string n, int r){
			setName(n);
			setRollNo(r);
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
		
		void printDetails() const{
			cout<<"Name: "<<name<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
		}
};



int main(){
	Student s1("Ali", 20);
	s1.setName("Ali Khan");
	s1.printDetails();
	
	const Student s2("Aslam1", 22);
	s2.printDetails();
	
	
}
