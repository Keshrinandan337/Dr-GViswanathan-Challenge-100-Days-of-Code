//leetcode 58
class Solution {
public:
    int lengthOfLastWord(string s) {
        // remove space from last
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        // count characters
        int count = 0;
        while(i >=0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }
};
