// leetcode 13
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['M'] = 1000;
        mp['D'] = 500;
        mp['C'] = 100;
        mp['L'] = 50;
        mp['X'] = 10;
        mp['V'] = 5;
        mp['I'] = 1;

        int n = s.size();
        int result = 0;
        for(int i = 0 ; i < n ; i++){
            if(mp[s[i]] < mp[s[i+1]]){
                result -= mp[s[i]];
            }
            else{
                result += mp[s[i]];
            }
        }
        return result;
    }
};
