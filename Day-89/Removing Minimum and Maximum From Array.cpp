//leetcode 2091
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // finding min and max element
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // finding min and max element index
        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == minVal){
                minIndex = i;
            }

            if(nums[i] == maxVal){
                maxIndex = i;
            }
        }
        // Case 1: Delete both from the left
        int deleteFromLeft = max(minIndex, maxIndex) + 1;

        // Case 2: Delete both from the right
        int deleteFromRight = n - min(minIndex, maxIndex);

        // Case 3: Delete one from left and one from right
        int deleteBothSides = (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex));

        // Return minimum deletions
        return min({deleteFromLeft, deleteFromRight, deleteBothSides});
    }
};
