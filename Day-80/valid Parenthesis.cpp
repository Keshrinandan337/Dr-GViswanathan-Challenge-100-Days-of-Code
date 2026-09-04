//leetcode 20
class Solution {
public:
    bool isValid(string s) {
        string str = "";
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                str = str + ch;
            }
            else{
                if(str.empty()){
                    return false;
                }

                if((ch == ')' && str.back() == '(') || (ch == ']' && str.back() == '[') || (ch == '}' && str.back() == '{')){
                    str.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        return str.empty();
    }
};
