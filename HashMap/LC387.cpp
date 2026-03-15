#include <iostream>
#include <unordered_map>
using namespace std;

int func(string s){
    int n = s.size();
    unordered_map<char, int>mp;

    for(char ch:s){
        mp[ch]++;
    }
    for(int i=0;i<n;i++){
        if(mp[s[i]]==1){
            return i;
        }
    }
    return -1;
}

int main(){
    string s = "loveleetcode";
    cout<< func(s);
    return 0;

}