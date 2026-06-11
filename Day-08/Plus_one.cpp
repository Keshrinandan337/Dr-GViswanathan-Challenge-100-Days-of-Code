
// Leetcode - 66

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1; // start with least signoficant bit
        while(i>=0){
            if(digits[i]<9){
                digits[i] += 1;
                return digits;
            }

            // else we get 9
            digits[i] = 0; 
            i--;
        }

        digits.insert(begin(digits),1); // 1 is carry forward till the end
        return digits;
    }
};
