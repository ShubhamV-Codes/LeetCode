#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>&nums){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums[0];

    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]>nums[high]){
            low = mid+1;
        }else{
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={3,4,5,6,1,2};
    cout<<findMin(nums)<<endl;
    return 0;
}