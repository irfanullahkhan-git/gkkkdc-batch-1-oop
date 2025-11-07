#include<iostream>
using namespace std;

//Access Control and Visibility
	// public = accessible anywhere the object is visible
	// protected = accessible in derived classes but not outside the class hierarchy
	// private =  accessible only inside the base class itself

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
	int rollNumber;
	
	public:
		Student(string n, int a, string nic, int r): Person(n, a, nic), rollNumber(r){
			
		}
		
		void study(){
			cout<<"Roll No: "<< rollNumber<<endl;
		}
};

int main(){
	
	Teacher t("Ali", 35, "1234567", "C++");
	
	t.displayTeacher();
	t.teach();
	
	Student s("Aslam", 20, "", 101);
	s.introduce();
	s.study();
	

}
