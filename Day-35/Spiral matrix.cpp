//leetcode 54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int start_row = 0;
        int start_col = 0;
        int end_row = row - 1;
        int end_col = col - 1;

        while(count < total){

            // starting row print ker do 
            for(int index = start_col; count < total && index <= end_col; index++){
                ans.push_back(matrix[start_row][index]);
                count++;
            }
            start_row++;

            // ending col print ker do
            for(int index = start_row; count < total && index <= end_row; index++){
                ans.push_back(matrix[index][end_col]);
                count++;
            }
            end_col--;

            // ending row print ker do
            for(int index = end_col; count < total && index >= start_col; index--){
                ans.push_back(matrix[end_row][index]);
                count++;
            }
            end_row--;

            // start col print ker do
            for(int index = end_row; count < total && index >= start_row; index--){
                ans.push_back(matrix[index][start_col]);
                count++;
            }
            start_col++;                       
        }
        return ans;
    }
};
