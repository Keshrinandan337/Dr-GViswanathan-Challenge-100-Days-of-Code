//leetcode 2149
// more optimal 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // initialize positive and negative index
        int pos = 0;
        int neg = 1;

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};




/*
class Solution {
public:

    // array for positive integer
    vector<int> positive_Array(vector<int>& nums){
        int n = nums.size();
        vector<int> positive;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                positive.push_back(nums[i]);
            }
        }
        return positive;
    }

    // array for -ve integers
    vector<int> negative_Array(vector<int>& nums){
        int n = nums.size();
        vector<int> negative;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }
        }
        return negative;
    }

    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive = positive_Array(nums);
        vector<int> negative = negative_Array(nums);

        vector<int> ans;
        for(int i = 0; i < positive.size(); i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        return ans;
    }
};
*/
