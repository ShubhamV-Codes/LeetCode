#include <iostream>
#include <unordered_map>
 #include <climits>
using namespace std;

int maxNumberOfBalloons(string text) {
        unordered_map<char, int>have;
        for(int i=0;i<text.size();i++){
            have[text[i]]++;
        }
        unordered_map<char,int>need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        
        int res=INT_MAX;
        for(auto it:need){
            char c = it.first;
            int fneed = it.second;
            int fhave = have[c];
            int t = fhave/fneed;
            res = min(res,t);
        }
        return res;
}

int main(){
    string text = "nlaebolko";
    cout<<maxNumberOfBalloons(text);
    return 0;
}