//leetcode 33
class Solution {

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;

            // if mid is the target
            if(nums[mid] == target){
                return mid;
            }

            // check left sorted array and right sorted array

            if(nums[mid] >= nums[start]){ // left sorted 
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid+1;
                }
            }
            else{// right sorted
                if(target >= nums[mid] && target <= nums[n-1]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
