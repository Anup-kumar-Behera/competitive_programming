#include"iostream"
using namespace std;

class anup{
	public:
		void setName(string x){
			name=x;
		}
		string getName(){
			return name;
		}
	private:
		string name;
};
int main()
{
	anup ao;
	ao.setName("anup kumar");
	cout<<ao.getName()<<endl;
	return 0;
}
