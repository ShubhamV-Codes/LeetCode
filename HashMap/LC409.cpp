#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
        unordered_map<char, int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        int odd =false;
        int res = 0;
        for(auto it:f){
            int val = it.second;
            if(val%2==0){
                res+=val;
            }else{
                odd = true;
            }
        }
        if(odd==false){
            return res;
        }else{
            for(auto it:f){
                int val = it.second;
                if(val%2==1){
                    res+=val-1;
                }
            }
            return res+1;
        }
}

int main(){
    string s = "aabbccccd";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}