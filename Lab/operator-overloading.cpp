#include<iostream>
using namespace std;


class Complex{
	public:
		int real;
		int imaginary;
		
		Complex(int r, int i): real(r), imaginary(i){
			
		}
		
		void display(){
			cout<<real<<" + "<<imaginary<<"i"<<endl;
		}
		
		void showDetails(){
			Complex * ptr = this;
			cout<<ptr;
		}
		
		Complex operator +(Complex p){
//			cout<<"\ncalling real:"<<real<<endl;
			Complex temp(0,0);
			temp.real = real + p.real;
			temp.imaginary = imaginary + p.imaginary;
			return temp;
		}
		
		Complex& operator ++(){
			++real;
			++imaginary;
			return *this;
		}
		
		Complex operator ++(int){
			Complex temp = *this;
			real++;
			imaginary++;
			return temp;			
		}	
};


int main(){
	Complex a(10, 3);
	Complex b(20, 4);
	Complex d(5, 5);
	
	a.display();
	b.display();
	
	Complex c = a + b + d;
	c.showDetails();
	return 0;
	Complex t = c++;
	
	t.display();
	c.display();
	
//	int i = 10;
//	cout<<i++;

}
