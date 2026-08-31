//leetcode 49
// optimal approach complexity = O(n*K)

class Solution {
public:

    string generate(string& word){
        int arr[26] = {0};
        for(char ch: word){
            arr[ch - 'a']++;
        }

        string new_word;
        for(int i = 0; i < 26; i++){
            int freq = arr[i];
            if(freq > 0){
                new_word += string(freq, i + 'a');
            }
        }
        return new_word; 
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans; 

        unordered_map<string,vector<string>> mp; // create map

        for(int i = 0; i < n; i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word); // store all vectors in map;
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};









/*

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans; 

        unordered_map<string,vector<string>> mp; // create map

        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]); // store all vectors in map;
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};*/
