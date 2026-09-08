//leetcode 2948
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;

        // sort that given vec array
        sort(vec.begin(),vec.end());

        int groupNumber = 0;

        // this map tell which number on what group
        unordered_map<int,int> groupToNumber;
        groupToNumber[vec[0]] = groupNumber;

        // this map tell which group contain what number
        unordered_map <int, list<int>> groupTolist;
        groupTolist[groupNumber].push_back(vec[0]);

        for(int i = 1; i < n; i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNumber++;
            }

            groupToNumber[vec[i]] = groupNumber;
            groupTolist[groupNumber].push_back(vec[i]);
        }

        // merge that both group to build answer
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int group = groupToNumber[num];

            // finding smallest available number in this group
            nums[i] = *(groupTolist[group].begin());
            groupTolist[group].pop_front(); // delete krdo used element ko
        }
        return nums;
    }
};




/*

// Brute force (give TLE)

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (true) {
                int smallValue = nums[i];
                int idx = -1;

                // Finding the smallest value that can be swapped with nums[i]
                for (int j = i + 1; j < n; j++) {

                    if (abs(nums[i] - nums[j]) <= limit) {

                        if (nums[j] < smallValue) {
                            smallValue = nums[j];
                            idx = j;
                        }
                    }
                }

                // If we found a smaller valid element, swap it
                if (idx != -1) {
                    swap(nums[i], nums[idx]);
                }
                else {
                    break;
                }
            }
        }

        return nums;
    }
};

*/
