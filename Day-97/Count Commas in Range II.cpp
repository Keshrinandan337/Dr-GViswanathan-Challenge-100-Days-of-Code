//leetcode 3871
#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll start = 1000;
        ll result = 0;

        while(start <= n){
            result += (n - start) + 1;
            start *= 1000;
        }      
        return result;
    }
};
