// leetcode 3302
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = checking number of characters of word2 that matched from word1[i.]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        // Build suffix information
        for (int i = n - 1; i >= 0; i--) {

            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        int jth = 0;
        int life = 1;

        for (int ith = 0; ith < m; ith++) {

            while (jth < n) {

                // Case 1: Characters match
                if (word1[jth] == word2[ith]) {

                    ans.push_back(jth);
                    jth++;
                    break;
                }

                // Case 2: Use the one allowed mismatch
                if (life == 1 &&
                    suf[jth + 1] <= ith + 1) {

                    ans.push_back(jth);
                    jth++;
                    life = 0;
                    break;
                }

                // Case 3: Skip this character
                jth++;
            }
        }
        // Could not find a valid index
        if (ans.size() != word2.size()) {
            return {};
        }

        return ans;
    }
};
