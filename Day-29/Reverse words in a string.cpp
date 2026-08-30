//leetcode 557
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        reverse(s.begin(),s.end());

        for(int i = 0; i < n; i++){
        // Store one word at a time
            string word = "";

           // Collect characters until a space is found and Add current character to the word
            while(i<n && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            // Add the word to the answer only if it is not empty
            if(word.size() > 0){
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};
