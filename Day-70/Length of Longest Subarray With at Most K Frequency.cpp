//leetcode 2958
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int result = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++;

            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
        }
        return result;
    }
};
