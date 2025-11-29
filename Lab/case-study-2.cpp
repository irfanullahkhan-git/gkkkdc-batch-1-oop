#include<iostream>
using namespace std;

class Box{
	private:
		string name;
		int length, width, height;
	public:
		Box(string n, int l, int w, int h): name(n), length(l), width(w), height(h){
			
		}
		
		friend Box compare(Box fb, Box sb);
		
		int getVolume(){
			return length *  width * height;
		}
		
		void display(){
			cout<<"Name: "<<name;
		}
		
		int operator > (Box b){
			int v1 = getVolume();
			int v2 = b.getVolume();
			
			if(v1 > v2){
				return 1;
			}else{
				return 0;
			}
		}
};


Box compare(Box fb, Box sb){
	if (fb > sb){
		return fb;
	}
	if(sb > fb){
		return sb;
	}
	Box temp("Unknow Box", 0, 0, 0);
	return temp;
}

int main(){
	Box b1("FamilyBox", 10, 10, 20);
	Box b2("PersonalBox",10, 7, 21);
	
	Box largerBox = compare(b1, b2);
	largerBox.display();
}




