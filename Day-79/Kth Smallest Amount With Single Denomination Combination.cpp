//leetcode 3116
class Solution {
public:
    typedef long long ll;

    ll CountSmaller(ll mid, vector<int>& coins){
        ll correctedCount = 0;
        int n = coins.size();

        for(int expression = 1; expression <= pow(2,n) - 1; expression++){ // 2^n-1 expression using (A U B) approach
            ll lcm = 0;
            ll order = 0; // even or odd order of expression

            for(int i = 0; i < n; i++){
                if(expression & (1 << i)){
                    order++;

                    if(lcm == 0){
                        lcm = coins[i];
                    }
                    else{
                        lcm = (lcm * coins[i]) / gcd(lcm,coins[i]);
                    }
                }
            }

            if(order % 2 == 0){ // even
                correctedCount -= mid/lcm;
            }
            else{ // odd
                correctedCount += mid/lcm;
            }
        }
        return correctedCount;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;
        ll left = 0;
        ll right = (ll)(*max_element(begin(coins),end(coins))) * k;

        while(left <= right){
            ll mid = left + (right - left)/2;

            if(CountSmaller(mid,coins) >= k){ //left side we can find kth smallest element
                result = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};
