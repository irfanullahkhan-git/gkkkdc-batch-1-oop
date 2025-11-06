#include<iostream>
using namespace std;

// Composition (has a): When one class (Class-A) contains objects of another class (Class-B) as data members

class Engine{
	int horsePower;
	string type;
	
	public: 
//		Engine(int hp, string t){
//			horsePower = hp;
//			type = t;
//		}

		Engine(int hp, string t) : horsePower(hp), type(t){
			cout<<"\nEngine object is being created\n";
		}
		
		~Engine(){
			cout<<"\nEngine destroyed\n";
		}
		
		void displayEngineInfo(){
			cout<<"\n Horse Power: "<< horsePower<<"\nType: "<<type;
		}
};

class Car{
	string name;
	string company;
	string model;
	Engine engine;
	
	public:
		Car(string n, string c, string m, int hp, string t): name(n), company(c), model(m), engine(hp, t){
			cout<<"\nCar object is being created\n";
		}
		
		~Car(){
			cout<<"\nCar destroyed\n";
		}
		
		void displayCarinfo(){
			cout<<"\nCar Name: "<<name<<"\n";
			cout<<"\nCar Company: "<<company<<"\n";
			cout<<"\nCar Model: "<<model<<"\n";
			engine.displayEngineInfo();
		}
};


int main(){
	Car c("Xyz", "Toyota", "2024", 1000, "petrol");
	c.displayCarinfo();
}
