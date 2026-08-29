// Leetcode 389
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();

        int ans = 0;

        for(int i =0; i<n; i++){
            ans = ans^s[i];
        }

        for(int i =0; i<m; i++){
            ans = ans^t[i];
        }

        return ans;
    }
};
