//leetcode 438
class Solution {
public:
    bool allZeroes(vector<int> counter){
        for(int &i : counter){
            if(i != 0){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string txt, string pat) {
       int n = txt.size();
        int k = pat.size();
        vector<int> counter(26,0);
        
        // count the freq of each character in counter
        for(int i = 0; i < k; i++){
            char ch = pat[i];
            counter[ch - 'a']++;
        }
        
        int i = 0;
        int j = 0;
        vector<int> result;
        
        while(j < n){
            counter[txt[j] - 'a']--;
            if(j-i+1 == k){
                if(allZeroes(counter)){
                    result.push_back(i);
                }
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;        
    }
};

