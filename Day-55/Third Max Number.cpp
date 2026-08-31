//leetcode 414
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long largest = LLONG_MIN;
        long sec_largest = LLONG_MIN;
        long third_largest = LLONG_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == largest || nums[i] == sec_largest || nums[i] == third_largest){
                continue;
            }

            if(nums[i] > largest){
                third_largest = sec_largest;
                sec_largest = largest;
                largest = nums[i];               
            }
            else if(nums[i] > sec_largest){
                third_largest = sec_largest;
                sec_largest = nums[i];
            }
            else if( nums[i] > third_largest){
                third_largest = nums[i];
            }
        }
        if(third_largest == LLONG_MIN){
            return largest;
        }
        return third_largest;
        
    }
};
