//leetcode 209
class Solution {
public:
    int Sum(vector<int>& nums){
        int sum = 0;
        for(int num: nums){
            sum = sum + num;
        }
        return sum;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        // return 0 if array contain number sum less then target
        int ArraySum = Sum(nums);
        if(ArraySum < target){
            return 0;
        }

        int i = 0; j = 0;
        int minLength = n;
        int sum = 0;

        while(j < n){
            sum += nums[j];
            while((sum) >= target){
                minLength = min(minLength, j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return minLength;
    }
};
