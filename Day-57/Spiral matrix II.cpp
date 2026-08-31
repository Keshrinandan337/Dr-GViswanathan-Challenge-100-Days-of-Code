//leetcode 59
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int count = 0;
        int value = 1;
        int total = n * n;

        int start_row = 0;
        int start_col = 0;
        int end_row = n - 1;
        int end_col = n - 1;

        while(count < total){

            // starting row print ker do 
            for(int index = start_col; count < total && index <= end_col; index++){
                matrix[start_row][index] = value++;
                count++;
            }
            start_row++;

            // ending col print ker do
            for(int index = start_row; count < total && index <= end_row; index++){
                matrix[index][end_col] = value++;
                count++;
            }
            end_col--;

            // ending row print ker do
            for(int index = end_col; count < total && index >= start_col; index--){
                matrix[end_row][index] =value++;
                count++;
            }
            end_row--;

            // start col print ker do
            for(int index = end_row; count < total && index >= start_row; index--){
                matrix[index][start_col] = value++;
                count++;
            }
            start_col++;                       
        }
        return matrix;        
    }
};
