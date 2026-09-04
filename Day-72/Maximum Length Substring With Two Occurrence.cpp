//leetcode 3090
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int length = 0;
        int i = 0;
        int freq[26]  {0};
        for(int j = 0; j<n; j++){
            freq[s[j] - 'a']++;
            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }
            length = max(length, j - i + 1);
        }
        return length;
    }
};
