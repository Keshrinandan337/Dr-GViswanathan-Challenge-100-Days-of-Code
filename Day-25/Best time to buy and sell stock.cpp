//leetcode 121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0; 
        int bestbuy = prices[0]; // starting index is bestbuy for now
        for(int i = 1; i < n ; i++){
            if(prices[i] > bestbuy){
                maxProfit = max(maxProfit, prices[i] - bestbuy);
            }
            bestbuy = min(prices[i],bestbuy);
        }
        return maxProfit;
    }
};
