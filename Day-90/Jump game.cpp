//leetcode 55
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(i > maxReach)
                return false;

            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};







/*

// DP Solution
class Solution {
public:
    int t[10001];
    bool solve(vector<int>& nums,int n, int idx){
        if(idx == n-1){
            return true;
        }

        if(t[idx] != -1){
            return t[idx];
        }

        for(int i = 1; i <= nums[idx]; i++){
            if(solve(nums, n, idx + i) == true){
                return t[idx] = true;
            }
        }
        return t[idx] =  false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, n, 0);
    }
};
*/
