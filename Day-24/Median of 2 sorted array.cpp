//leetcode 4
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // make nums1 array minimum for applying Binary Search
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;
        while(l<=r){
            int px = l + (r-l)/2;
            int py = ((m + n + 1)/2) - px;

            // left part
            int x1 = (px == 0) ? INT_MIN : nums1[px -1];
            int x2 = (py == 0) ? INT_MIN : nums2[py -1];

            // right part
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];

            if((x1<=x4) && (x2 <= x3)){
                if((m+n)%2 == 1){
                    return max(x1,x2);
                }
                else{
                    return (max(x1,x2) + min(x3,x4))/2.0;
                }
            }

            if(x1 > x4){
                r = px -1;
            }
            else {
                l = px + 1;
            }
        }
        return -1;
    }
};





// scroll below for other approach but not optimal


// Normal Approach

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         int size = m + n;

//         int idx1 = (size/2) - 1;
//         int element1 = -1;

//         int idx2 = size/2;
//         int element2 = -1;

//         int i = 0;
//         int j = 0;
//         int k = 0;

//         while(i<m && j<n){
//             if(nums1[i] < nums2[j]){
//                 if(k == idx1){
//                     element1 = nums1[i];
//                 }
//                 if(k == idx2){
//                     element2 = nums1[i];
//                 }
//                 i++;
//                 k++;
//             }
//             else{
//                 if(k == idx1){
//                     element1 = nums2[j];
//                 }
//                 if(k == idx2){
//                     element2 = nums2[j];
//                 }
//                 j++;
//                 k++;                
//             }
//         }

//         while(i<m){
//             if(k == idx1){
//                 element1 = nums1[i];
//             }
//             if(k == idx2){
//                 element2 = nums1[i];
//             }
//             i++;
//             k++;
//         }            
        

//         while(j < n){
//             if(k == idx1){
//                 element1 = nums2[j];
//             }
//             if(k == idx2){
//                 element2 = nums2[j];
//             }
//             j++;
//             k++;
//         }            
        

//         if((size%2) == 1){
//             return element2;
//         }
//         else{
//             return ((element1 + element2)/2.0);
//         }
//     }
// };
