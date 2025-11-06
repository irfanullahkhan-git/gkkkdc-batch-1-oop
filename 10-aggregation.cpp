#include<iostream>
using namespace std;

// Aggregation (has a): but unlike composition, both objects can exist independently.

class Teacher{
	
	string name;
	string qualification;
	
	public:
		Teacher(string n, string q): name(n), qualification(q){
			
		}
		
		string getTeacherName(){
			return name;
		}
		string getTeacherQualification(){
			return qualification;
		}
		
		~Teacher(){
			cout<<"Teacher object destroyed";
		}
};

class Department{
	string deptName;
	Teacher * teacher;
	
	public:
		Department(string dn, Teacher * t): deptName(dn), teacher(t){
			
		}
		
		~Department(){
			cout<<"Department object destroyed\n";
		}
		
		void displayDepartment(){
			cout<<"Department Name: "<<deptName<<endl;
			cout<<"Teacher Name: "<<teacher->getTeacherName()<<endl;
			cout<<"Teacher Qualificaiton: "<<teacher->getTeacherQualification()<<endl;
		}
};

int main(){
	Teacher t("Ali", "MS");
	Department d1("CS", &t);
	Department * d2 = new Department("Physics", &t);
	
	d2->displayDepartment();
	delete d2;
	
	d1.displayDepartment();
}
