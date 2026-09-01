//leetode 3979
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int best_left = 0;
        int ans = 0;
        for(int j = k; j < n; j++){
            // we find best left that never go to previous indices 
            best_left = max(best_left,nums[j-k]);

            // finding max sum
            ans = max(ans, best_left + nums[j]);
        }
        return ans;
    }
};
