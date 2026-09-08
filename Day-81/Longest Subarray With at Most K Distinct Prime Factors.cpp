//leetcode 4032
class Solution {
public:
    vector<int> get_prime_factors(int num){
        vector<int> factors;
        
        for(int i = 2; i*i <= num; i++){
            if(num % i == 0){
                factors.push_back(i);
            }

            // Remove all occurrences of this prime factor
            while(num % i == 0){
                num = num / i;
            }
        }

        // If a prime number greater than sqrt(num) bacha hai
        if(num > 1){
            factors.push_back(num);
        }
        return factors; 
    }
    
    int longestSubarray(vector<int>& nums, int k) {

        unordered_map <int,int> freq;
        
        // using sliding window
        int left = 0;
        int max_length = 0;

        for(int right = 0; right < nums.size(); right++){

            // Add distinct prime factors of nums[right]
            vector<int> factors = get_prime_factors(nums[right]);
            
            for(int factor : factors){
                freq[factor]++;
            }

            // Shrink window if we have more than k distinct prime factors
            while(freq.size() > k){
                vector<int> left_factor = get_prime_factors(nums[left]);

                for(int factor : left_factor){
                    freq[factor]--;

                    // Remove factor completely if no number uses it
                    if(freq[factor] == 0){
                        freq.erase(factor);
                    }
                }
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
