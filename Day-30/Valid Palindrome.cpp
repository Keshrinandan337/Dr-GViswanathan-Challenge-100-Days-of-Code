//leetcode 125
class Solution {
bool isValid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return 1;
    }
    return 0;
}

char lowercase(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
        return ch;
    }
    else{
        int temp = ch - 'A' + 'a';
        return temp;
    }
}

bool palindrome(string s){
    int i = 0;
    int j = s.size() - 1;
    while(i<=j){
        if(s[i] != s[j]){
            return 0;
        }
        else{
            i++;
            j--;
        }
    }
    return -1;
}
public:
    bool isPalindrome(string s) {
        string temp = "";

        // extra symbols hata do
        for(int i = 0; i < s.size(); i++){
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }

        // uppercase ko lowercase me convert ker do
        for(int i = 0; i < temp.size(); i++){
            temp[i] = lowercase(temp[i]);
        }
        
        // find palindrome
        return palindrome(temp);
    }
};
