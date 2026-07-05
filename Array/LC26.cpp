class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()<2){
            return nums.size();
        }

        int val = 1 ;
        int low=0;
        
       for(int high = 1;high<nums.size();high++){
        if(nums[high]!=nums[high-1]){
            low++;
            nums[low]=nums[high];
            val++;
        }
       }
       return val;
        
    }
};
