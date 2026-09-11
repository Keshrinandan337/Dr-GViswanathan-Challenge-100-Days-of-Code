//leetcode 76
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size() > n){
            return "";
        }
        // create a map to store t array character count
        unordered_map<char,int> mp;

        // storing t array character count
        for(char &ch: t){
            mp[ch]++;
        }

        int required_count = t.size();
        int minWindowSize = INT_MAX;
        int ist_index = 0;

        // sliding window
        int i = 0; 
        int j = 0;

        while(j < n){
            // take element at index j
            char ch = s[j];

            if(mp[ch] > 0){
                required_count--;
            }

            // always decrease count of jth element in map
            mp[ch]--;

            while(required_count == 0){
                // start shrinking the window
                int currentWindowSize = j - i + 1;

                if(currentWindowSize < minWindowSize){
                    minWindowSize = currentWindowSize;
                    ist_index = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    required_count++;
                }

                i++;
            }
            j++;
        }

        if(minWindowSize == INT_MAX){
            return "";
        }
        return s.substr(ist_index, minWindowSize);
    }
};
