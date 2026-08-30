//leetcode 11
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_water = 0;
        while(left<right){
            int weidth = right - left;
            int ht = min(height[left],height[right]);
            int current_max_water = weidth * ht;
            max_water = max(max_water,current_max_water);

            if(height[left] < height[right]){
                left++;
            }
            else right--;
        }
        return max_water;
    }
};
