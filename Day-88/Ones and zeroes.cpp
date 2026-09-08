//leetcode 474
class Solution {
public:
    int dp[101][101][601]; // creating dp memoization table

    int solve(vector<pair<int,int>>& count,int m, int n, int i){
        if(i >= count.size() || (m == 0 && n == 0)){ // Base case
            return 0;
        }

        if(dp[m][n][i] != -1){ // checking if this state has already been calculated
            return dp[m][n][i];
        }

        int take = 0;
        if(count[i].first <= m && count[i].second <= n){
            take = 1 + solve(count, m - count[i].first, n - count[i].second, i+1);
        }

        int skip = solve(count, m, n, i+1);
        return dp[m][n][i] = max(skip,take); // Store the answer in dp and return it
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int,int>> count(N); //For Store zeros and ones count for each string

        for(int i = 0; i < N; i++){
            int countZeroes = 0;
            int countOnes = 0;

            for(const char& ch : strs[i]){
                if(ch == '0'){
                    countZeroes++;
                }
                else{
                    countOnes++;
                }
            }
            count[i] = {countZeroes, countOnes}; // adding values inside count
        }
        
        memset(dp,-1,sizeof(dp));
        return solve(count, m, n, 0);
    }
};
