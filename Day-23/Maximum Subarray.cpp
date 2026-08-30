//leetcode 53
// Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int totalSum = 0;
        for(int i = 0;i<nums.size();i++){
            totalSum += nums[i];
            maxSum = max(totalSum,maxSum);
            if(totalSum < 0){
                totalSum = 0;
            }
        }
        return maxSum;
    }
};
