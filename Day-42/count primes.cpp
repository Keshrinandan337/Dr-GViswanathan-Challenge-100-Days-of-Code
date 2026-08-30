//leetcode 204
// Sieve of Eratosthenes best optimal approach

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool>is_prime(n,true);
        is_prime[0] = false;
        is_prime[1] = false;

        for(int i = 2; i*i < n; i++){
            if(is_prime[i]){           
                for(int j = i*i; j < n; j=j+i){
                    is_prime[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(is_prime[i]){
                ans++;
            }
        }
        return ans;
    }
};





// Sieve of Eratosthenes optimal approach

/*
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>is_prime(n,true);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(is_prime[i]){
                ans++;
            
                for(int j = i*i; j < n; j=j+i){
                    is_prime[j] = false;
                }
            }
        }
        return ans;
    }
};
*/
