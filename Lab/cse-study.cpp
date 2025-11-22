#include<iostream>
#include<conio.h>
using namespace std;

/*
	Product
		- Price, Description, Quantity
	: EelectronicDevices
		- Warrenty
	: Clothing
		- Size
	
	Cart:
		- * items[] (Product) max-20
	
	PaymentInfo:
		- CardNo, CardPin, BillingAddress
	Customer:
		has a: cart
		has a: payment information	

*/

class Product{
	string price, description;
	int quantity;
	
	public: 
		Product(string p, string desc, int q): price(p), description(desc), quantity(q){
			
		}
};

class EelectronicDevices: public Product{
	string warrenty;
	public:
		EelectronicDevices(string p, string desc, int q, string w): Product(p, desc, q), warrenty(w){
			
		}
};

class Clothing: public Product{
	int size;
	public:
		Clothing(string p, string desc, int q, int sz): Product(p, desc, q), size(sz){
			
		}
};

class Cart{
	Product * items[10];
	int totalProducts;
	
	public:
		Cart(){
			totalProducts = 0;
		}
		void addItemToCart(Product * pro){
			if(totalProducts < 10){
				items[totalProducts] = pro;
				totalProducts++;
			}else{
				cout<<"Cart is full";
			}
		}
};

class PaymentInfo{
	string cardNo, billingAddress;
	int cardPin;
	
	public:
		PaymentInfo(string cn, string ba, int cp): cardNo(cn), billingAddress(ba), cardPin(cp){
			
		}
};


class Customer{
	string name;
	Cart cart;
	PaymentInfo payment_info;
	
	public:
		Customer(string n, string cn, string ba, int cp): payment_info(cn, ba, cp), name(n){
			
		}
		
};


int main(){
	Product * allProducts[50];
	int totalProducts = 0;
	int flag = 1;
	while(flag){
		cout<<endl<<"Add Product:\n";
		cout<<"Press 1 for Clothing and 2 for Electronic Devices\n";
		int input = 0;
		string pName, pDesc;
		int pQuantity;
		
		cin>> input;
		cout<<" Enter Product Name: ";
		cin>>pName;
		cout<<" Enter Product Description: ";
		cin>>pDesc;
		
		cout<<" Enter Product Quantity: ";
		cin>>pQuantity;
		
		if(input == 1){
			int size;
			cout<<"Enter Size: ";
			cin>>size;
			allProducts[totalProducts++] = new Clothing(pName, pDesc, pQuantity, size);
		}else{
			string warrenty;
			cout<<"Enter Warrenty: ";
			cin>>warrenty;
			allProducts[totalProducts++] = new EelectronicDevices(pName, pDesc, pQuantity, warrenty);
		}
		
		cout<<"Do you want to add more Products? 1 for Yes, 0 for No\n";
		cin>>flag;
	}
	
	
	
		
	
}



