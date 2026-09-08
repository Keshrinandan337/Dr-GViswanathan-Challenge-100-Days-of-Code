//leetcode 503
// For circular traversal we use i % n to retraverse starting value 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        //creating stake to store and find next greater value
        stack<int> s;

        //creating ans to push all gretest element of nums arr value
        vector<int> ans(n,0);

        for(int i = 2*n - 1; i >= 0; i--){
            while(s.size() > 0 && s.top() <= nums[i%n]){
                s.pop();
            }

            if(s.empty()){
                ans[i%n] = -1;
            }
            else{
                ans[i%n] = s.top();
            }

            s.push(nums[i%n]);
        }

        return ans;       
    }
};
