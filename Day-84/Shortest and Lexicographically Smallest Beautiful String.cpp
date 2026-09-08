//leetcode 2904
// Sliding window
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int j = 0;

        int n = s.size();
        int ones = 0;
        string result = "";

        while(j < n){
            if(s[j] == '1'){
                ones++;
            }

            while(ones > k || (ones == k && s[i] == '0')){ // shrink case
                if(s[i] == '1'){
                    ones--;
                }
                i++;
            }

            if(ones == k){ // Beautiful substring
                string temp = s.substr(i, j-i+1);
                if(result.empty() || (j-i+1) < result.size() || (result.size() == temp.size() && temp < result)){
                    result = temp;
                }
            }
            j++;
        }
        return result;
    }
};
