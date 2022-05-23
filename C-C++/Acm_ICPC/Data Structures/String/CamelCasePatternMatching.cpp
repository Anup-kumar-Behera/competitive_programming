#include<bits/stdc++.h>

using namespace std;

void camelCase(vector<string>& words,string pattern)
{
	map<string,vector<string> > map;
	
	for(int i = 0;i < words.size() ;i++)
	{
		string str = "";
		
		int l = words[i].length();
		for(int j = 0;j < l;j++)
		{
			if(words[i][j] >= 'A' && words[i][j] <= 'Z')
			{
				str += words[i][j];
				map[str].push_back(words[i]);
			}
		}
	}
	bool wordFound = false;
	
	for(auto& it :map)
	{
		if(it.first == pattern)
		{
			wordFound = true;
			for(auto& itt : it.second)
			{
				cout<<itt<<endl;
			}
		}
	}
	
	if(!wordFound)
	{
		cout<<"No match found.";
	}
}

int main()
{
	vector<string> words = {"Hi","Hello","HelloWorld","HiTech","HiGeek",
	"HiTechWorld","HiTechCity","HiTechLab"};
	
	string pattren = "HT";
	
	camelCase(words,pattern);
	
	return 0;
}
