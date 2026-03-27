#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // Min heap based on frequency
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        unordered_map<int,int> f;
        vector<int> res;

        // Count frequency
        for(int i = 0; i < n; i++){
            f[nums[i]]++;
        }

        // Process map
        for(auto it : f){
            int el = it.first;
            int freq = it.second;

            pair<int,int> curr = {freq, el};

            if(pq.size() < k){
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first) continue;

            pq.pop();
            pq.push(curr);
        }

        // Extract result
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements:\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}