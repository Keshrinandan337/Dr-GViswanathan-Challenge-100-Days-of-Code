//leetcode 29
class Solution {
public:
    int divide(int dividend, int divisor) {

       // If both numbers are same, answer is always 1 
        if(dividend == divisor){
            return true;
        }

        bool sign = true;

        // Different signs → answer will be negative
        if(dividend <= 0 && divisor > 0){
            sign = false;
        }       
        else if(dividend >= 0 && divisor < 0){
            sign = false;
        }

        // Convert both numbers into positive long long
        // long long is needed for INT_MIN
        long long numerator = abs((long long)dividend); 
        long long denominator = abs((long long)divisor); 

        long long ans = 0;

        // Keep dividing until numerator becomes smaller
        while(numerator >= denominator){
            int count = 0;
            while(numerator >= (denominator << count + 1)){
                count += 1;
            }
            ans += 1LL << count;
            numerator -= (denominator << count);
        }

        // Handle positive overflow
        if(ans > INT_MAX && sign){
            return INT_MAX;
        }

        // Handle negative overflow
        if(ans > INT_MAX && !sign){
            return INT_MIN;
        }

        if(sign){
            return ans;
        }
        return -ans;
    }
};
