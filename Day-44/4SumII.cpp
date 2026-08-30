//leetcode 454
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                mp[nums1[i] + nums2[j]]++;
            }
        }

        int count = 0;
        for(int k = 0; k < n3; k++){
            for(int l = 0; l < n4; l++){
                int sum = nums3[k] + nums4[l];
                if(mp.find(-sum) != mp.end()){
                    count += mp[-sum];
                }
            }
        }
        return count;
    }
};
