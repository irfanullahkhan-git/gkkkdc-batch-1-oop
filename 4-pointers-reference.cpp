#include<iostream>
using namespace std;


int main(){
	int a = 10;
	int *ptr = &a;
	
	cout<<"Value of a: "<< *ptr<<endl;
	cout<< "Address: " << ptr<<endl;
	
	int b = 20;
	ptr = &b;
	
	cout<<"Value of b: "<< *ptr<<endl;
	cout<< "Address: " << ptr<<endl;
	
	// Reference:
	
	int num = 15;
	int &ref = num;
	cout<<"The value of Num: "<< num << endl;
	cout<<"The value of Ref: "<< ref << endl;
	
	ref++;
	cout<<"The value of Num: "<< num << endl;
	
	int num2 = 20;
	ref = num2;
	
	cout<<"The value of Num: "<< num << endl;

	
	
}
