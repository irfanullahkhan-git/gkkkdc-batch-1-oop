#include<iostream>
using namespace std;

class person{
	public:
		string name;
		int age;
		string address;
		
		void displayDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Address: "<<address<<endl;
		}
};
class teacher : public person{
	public:
		int salary;
		void displaySalary(){
			cout<<"Salary: "<<salary<<endl;
		}
};

class student : public person{
	public:
		int class_no;
		void displayClass(){
			cout<<"Class: "<<class_no<<endl;
		}
};

int main(){
	student s;
	s.name = "Ali";
	s.age = 10;
	s.address = "Nowshera";
	s.class_no = 5;
	
	s.displayDetails();
	s.displayClass();
	
	teacher t;
	t.name = "Aslam";
	t.age = 30;
	t.address = "Peshawar";
	t.salary = 50000;
	
	t.displayDetails();
	t.displaySalary();
	
	
	
	
	
	
	
	
	
}










