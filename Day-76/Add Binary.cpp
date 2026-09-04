//leetcode 67
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = m-1;

        int carry = 0;
        string ans = "";

        while(i >=0 || j >= 0 || carry){
            int sum = carry;

            if(i >= 0){
                sum = sum + a[i] - '0'; // convert char to integer
                i--;
            }

            if(j >= 0){
                sum = sum + b[j] - '0'; // convert char to integer
                j--;
            }

            int bit = sum % 2; // convert integer_sum to bit
            ans += bit + '0'; // convert integer to char
            carry = sum / 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
