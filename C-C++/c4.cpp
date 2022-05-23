#include"iostream"
using namespace std;

class car{
	public:
		void a(){
			cout<<"Anup kumar is a good boy."<<endl;
		}
		string name;
};
int main()
{
	car func;
	func.a();
	func.name="shruti gupta";
	cout<<func.name<<endl;
	return 0;
}
