//leetcode 1672
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int max_sum = INT_MIN;  
        for(int row = 0; row < m; row++){
            int sum = 0;
            for(int col = 0; col < n; col++){
                sum += accounts[row][col];
            }
            if(sum >= max_sum){
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
