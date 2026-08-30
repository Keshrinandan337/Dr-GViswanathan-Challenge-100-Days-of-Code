//leetcode 611
// Complexity O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        sort(nums.begin(),nums.end()); // main point of this code
        int count = 0;
        for(int k = n-1; k >= 2; k--){
            int i = 0;
            int j = k-1;
            while(i<j){
                if(nums[i] + nums[j] > nums[k]){
                    count += j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
       return count; 
    }
};




/* Complexity O(n^2 logn)

class Solution {
public:

    int binarysearch(vector<int>& nums,int start, int end, int target){
        int k = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                k = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        sort(nums.begin(),nums.end()); // main point of this code
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;

            for(int j = i+1; j < n; j++){
                int sum = nums[i] + nums[j];
                int k = binarysearch(nums,j+1,n-1,sum);
                if(k != -1){
                    count += (k-j);
                }
            }
        }
       return count; 
    }
};*/
