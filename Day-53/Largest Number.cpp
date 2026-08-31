//leetcode 179
class Solution {
public:
    string largestNumber(vector<int>& nums) {

    auto comparitor = [](int& a, int& b){ // comparitor lamda fn.
        string s1 = to_string(a);
        string s2 = to_string(b);
        if(s1 + s2 > s2 + s1){
            return true;
        }
        return false;
    };

        sort(nums.begin(), nums.end(),comparitor); // conparitor work when its static 
        if(nums[0] == 0){
            return "0";
        }
        string result = "";
        for(int& x: nums){
            result += to_string(x);
        }
        return result;
    }
};






/*
class Solution {
public:

    static bool comparitor(int& a, int& b){ // comparitor fn.
        string s1 = to_string(a);
        string s2 = to_string(b);
        if(s1 + s2 > s2 + s1){
            return true;
        }
        return false;
    };

    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(),comparitor); // conparitor work when its static 
        if(nums[0] == 0){
            return "0";
        }
        string result = "";
        for(int& x: nums){
            result += to_string(x);
        }
        return result;
    }
};*/
