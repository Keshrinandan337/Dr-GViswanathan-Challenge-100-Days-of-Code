
// Leetcode question-191

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n != 0){
            // Checking last bit 
            if(n & 1 == 1){
                count++ ;
            }
            n = n >> 1 ;
        }
        return count;
    }
};
