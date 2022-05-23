#include <bits/stdc++.h>
using namespace std;


int getCharCnt(string word, int startIdx) {
        int cnt = 0;
        char searchChar = word[startIdx];
        
        while (word[startIdx] == searchChar && startIdx < word.size()) {
            startIdx++;
            cnt++;
        }
        
        return cnt;
    }
    
    bool isStretchy(string word, string s) {
        int wIdx = 0, sIdx = 0;
        
        while (wIdx < word.size() && sIdx < s.size()) {
            if (word[wIdx] != s[sIdx]) {
                    return false;
            }
            
            int wCnt = getCharCnt(word, wIdx);
            int sCnt = getCharCnt(s, sIdx);
            
            if (wCnt > sCnt || ((wCnt != sCnt) && (sCnt < 3))) {
                return false;
            }
            
            wIdx += wCnt;
            sIdx += sCnt;
        }
        
        return (wIdx == word.size() && sIdx == s.size());
    }
    int expressiveWords(string s, vector<string>& words) {
        int expressiveWordCnt = 0;
        
        for (int i = 0; i < words.size(); i++) {
            if (isStretchy(words[i], s)) {
                expressiveWordCnt++;
            }
        }
        
        return expressiveWordCnt;
    }
    
int main(){
	string s = "wuuusssuup";
	
	vector<string> v;
	
	v.push_back("wussup");
	v.push_back("wuup");
	v.push_back("wuuusssuup");
	v.push_back("wusuuup");
	v.push_back("wuusupg");
	v.push_back("wuusuup");
	cout<<expressiveWords(s, v)<<endl;
}
