//leetcode 867
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Store the transposed matrix
        vector<vector<int>> ans;

        for(int col = 0; col < n; col++){
            
            // Store one row of the transposed matrix
            vector<int> temp;

            for(int row = 0; row < m; row++){
                temp.push_back(matrix[row][col]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
