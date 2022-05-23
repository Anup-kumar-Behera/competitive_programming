#include<iostream>
using namespace std;


//virtual destructor
class b{
	public:
		b(){
			cout<<"constructor b is called.\n";
		}
		virtual ~b(){
			cout<<"destructor b is called.\n";
		}
};
class d: public b{
	public:
		d(){
			cout<<"constructor d is called.\n";
		}
		~d(){
			cout<<"destructor d is called.\n";
		}
};

int main(){
	d *derived = new d();
	b *p = derived;
	
	delete p;
}
/*class Point{
	public:
		int a, b;
		
		
		Point(int x, int y){
			a = x;
			b = y;
		}
};

int main(){
	Point p;
	cout<<"a: "<<p.a<<" b: "<<p.b;
}

/*class classA{
	public:
		classA(){
			cout<<"Class constructor is called"<<endl;
		}
		~classA(){
			cout<<"Class destructor is called.\n";
		}
};

int main(){
	classA a;
	int p = 1;
	if(p){
		//classA b;
	}
	
	for(int i = 0; i < 20; i++)
		cout<<"fuck you"<<endl;
}

/*class guru99{
	public:
		string t_name;
		int id;
		void printname();
		void printid(){
			cout<<"t id is: "<<id;
		}
};
void guru99::printname(){
	cout<<"t name is: "<<t_name;
}
int main(){
	guru99 g;
	g.t_name = "c++";
	g.id = 101;
	g.printname();
	cout<<endl;
	g.printid();
	
}

/*class parentClass{
	protected:
		int value;
};
class childClass: public parentClass{
	public:
		void setId(int x){
			value = x;
		}
		void displayValue(){
			cout<<"Value is: "<<value<<endl;
		}
};
int main(){
	childClass c;
	c.setId(21);
	c.displayValue();
}



/*class classA{
	public:
		void set_a(int val);
		int get_a(void);
	private:
		int a;
};
int classA::get_a(void){
	return a;
}
void classA::set_a(int val){
	a = val;
}
int main(){
	classA a;
	a.set_a(21);
	cout<<"Value of a is: "<<a.get_a();
	return 0;
}*/

