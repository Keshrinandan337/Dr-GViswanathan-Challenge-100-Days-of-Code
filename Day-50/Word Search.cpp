//leetcode 79
class Solution {
public:

    vector<vector<int>> directions = {{0, 1},{0,-1},{1, 0},{-1, 0}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {

        int m = board.size();
        int n = board[0].size();

        // Base case
        if (idx == word.size()) {
            return true;
        }

        // Boundary checks
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }

        // Character doesn't match
        if (board[i][j] != word[idx]) {
            return false;
        }

        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 directions
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word)) {
                return true;
            }
        }

        // Backtrack
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
