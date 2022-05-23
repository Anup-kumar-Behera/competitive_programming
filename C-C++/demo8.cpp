#include<bits/stdc++.h>
using namespace std;

int maximumUnits(vector<vector<int> >& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        vector<pair<int, int> > v;
        
        for(int i = 0; i < boxTypes.size(); i++){
            for(int j = 0; j < boxTypes[i].size(); j++){
                v.push_back(make_pair(boxTypes[i][1], boxTypes[i][0]));
            }
        }
        sort(v.rbegin(), v.rend());//, greater<int>());
        
        int ans = 0;
        for(int i = 0; i < n; i++){
           
            if(truckSize >= v[i].second){
                ans += v[i].first * v[i].second;
                truckSize -= v[i].second;
                if(truckSize == 0)
                    break;
            }
            else if(truckSize <= v[i].second){
                 ans += v[i].first * truckSize;
                truckSize -= v[i].second;
                if(truckSize == 0)
                    break;
            }
            
        }
        return ans;
    }
    
int main(){
	vector<vector<int, int> > v {{5,10},{2,5},{4,7},{3,9}};
	int truckSize = 10;
	
	//boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
	cout<<maximumUnits(v, 10);
}
