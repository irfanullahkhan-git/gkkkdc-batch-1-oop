#include<iostream>
using namespace std;

// Types of Inheritance
//		Multi Level Inheritance: A class is derived from another derived class.

class Person{
	
	private:
		string nic_no;
	
	protected:
		int age;
		
	public:
		
		string name;
		
		Person(string n, int a, string nic): name(n), age(a), nic_no(nic){
			
		}
		
		void introduce(){
			cout<<"Name: "<<name<<" Age: "<<age<<endl;
		}
};

class Teacher : public Person{
	string subject;
	
	public: 
		Teacher(string n, int a, string nic, string s): Person(n, a, nic), subject(s){
			
		}
		
		void displayTeacher(){
			cout<<"Teacher Name: "<< name <<" Teacher Age: "<< age <<" Teacher NIC: " <<endl;
		}
		
		void teach(){
			cout<<"Subject: "<<subject<<endl;
		}
	
};

class Student: public Person{
	protected:
	int rollNumber;
	
	public:
		Student(string n, int a, string nic, int r): Person(n, a, nic), rollNumber(r){
			
		}
		
		void study(){
			cout<<"Roll No: "<< rollNumber<<endl;
		}
};

class GraduatedStudent : public Student{
	string fypTitle;
	
	public:
		GraduatedStudent(string n, int a, string nic, int r, string fyp) : Student(n, a, nic, r), fypTitle(fyp){
			
		}
		
		void displayGraduatedStudent(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			
			cout<<"Roll Number: "<<rollNumber;
		}
		
		void displayFyp(){
			cout<<"FYP: "<<fypTitle<<endl;
		}
};

int main(){
	
	GraduatedStudent gs("Ali", 20, "1233444", 101, "XYZ AI System");
//	gs.displayGraduatedStudent();
	gs.introduce(); // from Person
	gs.study(); // from Student
	gs.displayFyp(); // from GraduatedStudent
	

}
