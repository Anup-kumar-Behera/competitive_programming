#include <iostream>
using namespace std;

class Demo{
	int data;
	public:
		Demo(){
			cout<<"Default constructor is called!"<<endl;
		}
		Demo(int data){
			this->data = data;
//			
			cout<<"Parameterized constuctor"<<endl;
			cout<<"data: "<<data<<endl;
		}
		void dsp(){
			cout<<"dsp data: "<<data<<endl;
		}
		~Demo(){
			cout<<"Destructor for data: "<<data<<" is called"<<endl;
		}
};

int main(){
	
	Demo a(56);
	Demo *b = new Demo(67);
	a.dsp();
	b->dsp();
	Demo c(89);
}
