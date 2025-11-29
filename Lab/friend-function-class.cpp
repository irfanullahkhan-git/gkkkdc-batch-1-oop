#include<iostream>
using namespace std;

class A{
	private:
		int number;
	public:
		A(int num): number(num){
			
		}
		friend void display(A o);
		friend class B;
};

class B{
	public:
		void print(A obj){
			cout<<"From B: "<<obj.number;
		}
};

void display(A obj){
	cout<<obj.number;
}



int main(){
	A obj(10);
	display(obj);
	B b;
	
	b.print(obj);
	
}
