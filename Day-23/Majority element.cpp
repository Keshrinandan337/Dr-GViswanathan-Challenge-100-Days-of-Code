//leetcode 169
// Moore's Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i< n ; i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        // check if majority element is not present 
        int count = 0;
        for(int val = 0; val < n;val++){
            if(nums[val] == ans){
                count++;
            }
        }

        if(count > n/2){
            return ans;
        }
        else{
            return -1;
        }
    }
};
