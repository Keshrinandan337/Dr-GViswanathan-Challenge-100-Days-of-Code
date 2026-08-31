// leetcode 80
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int val: nums){
            if(  i < 2 || val != nums[i-2]){
                nums[i] = val;
                i++;
            }
        }
        return i;
    }
};
