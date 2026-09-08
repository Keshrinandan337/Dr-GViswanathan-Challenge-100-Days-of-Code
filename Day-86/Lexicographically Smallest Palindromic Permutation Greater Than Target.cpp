//leetcode 3734
class Solution {
public:
    int midCharacter = '$';
    int halfLength = 0; 
    string result = "";

    bool solve(string& current, vector<int>& count, string& target, int i, bool greater){
        if(current.size() == halfLength){
            string candidate = current; // lefthalf
            string righthalf = current;
            reverse(righthalf.begin(),righthalf.end());

            if(midCharacter != '$'){
                candidate += midCharacter;
            }

            candidate += righthalf;

            if(candidate > target){ // base case
                result = candidate;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch - 'a'] == 0){
                continue;
            }

            if(!greater && ch < target[i]){
                continue;
            }

            //Do
            current.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(current, count, target, i + 1, isGreater)){
                return true;
            }

            //Undo
            current.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> count(26,0);

        for(char &ch: s){
            count[ch - 'a']++;
        }

        int oddCount = 0; // odd freq wale kitne character hai pata karo
        for(int c = 0; c < 26; c++){
            if(count[c] % 2 == 1){
                oddCount++;
                midCharacter = c + 'a';
            }
        }

        if(oddCount > 1){
            return ""; //not possible to make a palendrome
        }
        
        //for left half of palindrome
        for(int c = 0; c < 26; c++){
            count[c] /= 2;
        }

        halfLength = n/2;

        string current; // left half
        solve(current, count, target,0,false);
        return result;
    }
};
