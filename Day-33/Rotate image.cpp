//leetcode 48
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Step 1: Transpose the matrix for n*n
        for(int row = 0; row < n; row++) {
            for(int col = row + 1; col < n; col++) {

                // Swap upper triangle with lower triangle
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row
        for(int row = 0; row < n; row++) {

            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};
