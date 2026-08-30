//leetcode 540
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        // Only one element
        if (n == 1) return nums[0];

        while(start <= end){
            int mid = start + (end - start)/2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid]; // Check if first element is the single element
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];  // Check if last element is the single element

            // If current element is different from both neighbors, then it is the unique element
            if((nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])){
                return nums[mid];
            }

            if(mid % 2 == 0){ // Case 1 : mid is at an even index
                if(nums[mid] == nums[mid-1]){
                    end = mid-1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{ // Case 2 : mid is at an odd index
                if(nums[mid] == nums[mid-1]){
                    start = mid + 1;
                }
                else{
                    end = mid-1;
                }                
            }
        }
        return -1;
    }
};






/* Using O(n) complexity

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // Only one element
        if (n == 1) return nums[0];

        // Check first element
        if (nums[0] != nums[1]) return nums[0];

        // Check last element
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        for(int i = 1; i < n-1; i++){
            if((nums[i] == nums[i+1])|| (nums[i] == nums[i-1])){
                continue;
            }
            else{
                ans = nums[i];
            }
        }
        return ans;
    }
};




Using O(n) complexity

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};*/
