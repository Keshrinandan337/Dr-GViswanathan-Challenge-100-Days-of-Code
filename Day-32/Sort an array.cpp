//leetcode 912
// Counting sort approach
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // find max and min element 
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());

        vector<int>count((maxE - minE + 1),0);
        // store count of each element
        for(int num : nums){
            count[num - minE]++;
        }

        int i = 0;
        for(int num = minE; num <= maxE; num++){
            while(count[num - minE] > 0){
                nums[i] = num;
                i++;
                count[num - minE]--;
            }
        }
        return nums;
    }
};


/* Counting sort approach using map 

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // find max and min element 
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());

        unordered_map <int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        int i = 0;
        for(int num = minE; num <= maxE; num++){
            while(mp[num] > 0){
                nums[i] = num;
                i++;
                mp[num]--;
            }
        }
        return nums;
    }
}; */
