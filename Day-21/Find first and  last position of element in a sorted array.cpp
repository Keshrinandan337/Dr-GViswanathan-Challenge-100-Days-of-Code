// leetcode 34
class Solution {
public:
  
    int leftOccurence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start)/2;
        int result = -1;
        while(start <= end){
            if(nums[mid] == target){
                result = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result;
    }

    int rightOccurence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start)/2;
        int result = -1;
        while(start <= end){
            if(nums[mid] == target){
                result = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return result;       
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = leftOccurence(nums,target);
        int last = rightOccurence(nums,target);
        return {first,last};  
    }
};



/* using upper and lower bound 

class Solution {
public:
  
    int leftOccurence(vector<int>& nums, int target){
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }

    int rightOccurence(vector<int>& nums, int target){
        return upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;    
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = leftOccurence(nums,target);
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        
        int last = rightOccurence(nums,target);
        return {first,last};  
    }
}; */
