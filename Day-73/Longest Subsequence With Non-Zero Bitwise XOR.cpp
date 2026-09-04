//leetcode 3702
class Solution {
public:
    int check_XOR(vector<int>& nums){
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }
        return ans;       
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(check_XOR(nums) != 0){
            return n;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                return n - 1;
            }
        }
        return 0;
    }
};
