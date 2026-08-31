//leetcode 5
// NOT Optimal O(n^3) time complexity
class Solution {
public:
    bool solve(string& s, int i, int j){ // checking palindrome
        if(i >= j){
            return 1;
        }
        if(s[i] == s[j]){
            return solve(s,i+1,j-1);
        }
        return 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = INT_MIN;
        int start_position = -1;

        for(int i = 0;i < n; i++){ // O(n)
            for(int j = i; j < n; j++){ // O(n)
                if(solve(s,i,j)){ // O(n)
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        start_position = i;
                    }
                }
            }
        }
        return s.substr(start_position, max_len);
    }
};
