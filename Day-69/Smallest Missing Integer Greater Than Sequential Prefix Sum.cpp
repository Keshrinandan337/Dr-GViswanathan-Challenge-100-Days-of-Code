//leetcode 2996
class Solution {
public:
    int longest_prefix_sum(vector<int>& nums){
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1] + 1){
                break;
            }
            sum = sum + nums[i];
        }
        return sum;
    }

    bool present(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return true;
        }
        return false;
    }
    
    int missingInteger(vector<int>& nums) {
        int value_sum = longest_prefix_sum(nums);

        // checking number present or not
        while(present(nums,value_sum)){
            value_sum++;
        }
        return value_sum;
    }
};
