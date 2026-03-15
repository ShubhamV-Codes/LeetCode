#include <iostream>
#include <unordered_map>
using namespace std;

bool ransom(string ransomNote, string magazine){
    unordered_map<char, int>mp;
    for(char ch: magazine){
        mp[ch]++;
    }
    for(char ch:ransomNote){
        mp[ch]--;
        if(mp[ch]<0)return false;
    }
    return true;
}

int main(){
    string magazine = "aab";
    string ransomNote = "aa";
    cout << ransom(ransomNote, magazine);
    return 0;
}