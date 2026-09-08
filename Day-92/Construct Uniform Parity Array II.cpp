//leetcode 3876
class Solution {
public:
    // check array contain all even or not
    bool Evencheck(vector<int>& nums1){
        for(int x: nums1){
            if(x % 2 != 0){
                return false;
            }
        }
        return true;
    }

    bool uniformArray(vector<int>& nums1) {

        int minimum = *min_element(nums1.begin(),nums1.end());

        // case1 if minimum number is odd
        if(minimum % 2 == 1){
            return true;
        }

        // case2 if all number in an array is even 
        if(Evencheck(nums1)){
            return true;
        }

        return false;
    }
};
