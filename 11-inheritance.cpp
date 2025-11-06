#include<iostream>
using namespace std;

// Inheritance (is-a): child class gets properties and behaviour of parent class.
// Parent class -> Base calss, Child class -> Derived class

class Person{
	string name;
	int age;
	
	public:
		Person(string n, int a): name(n), age(a){
			
		}
		
		void introduce(){
			cout<<"Name: "<<name<<" Age: "<<age<<endl;
		}
};

class Teacher : public Person{
	string subject;
	
	public: 
		Teacher(string n, int a, string s): Person(n, a), subject(s){
			
		}
		
		void teach(){
			cout<<"Subject: "<<subject<<endl;
		}
	
};

class Student: public Person{
	int rollNumber;
	
	public:
		Student(string n, int a, int r): Person(n, a), rollNumber(r){
			
		}
		
		void study(){
			cout<<"Roll No: "<< rollNumber<<endl;
		}
};

int main(){
	
	Teacher t("Ali", 35, "C++");
	
	t.introduce();
	t.teach();
	
	Student s("Aslam", 20, 101);
	s.introduce();
	s.study();
	

}
