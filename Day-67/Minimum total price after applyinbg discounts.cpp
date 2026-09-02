//leetcode 4014
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int no_of_prices = prices.size();
        int no_of_discounts = discounts.size();
        
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());

        int p = 0;
        int d = 0;
        double sum = 0;
        while(p < no_of_prices){
            if(d < no_of_discounts){
                sum = sum + (prices[p] * (100 - discounts[d])) / 100.00;
                d++;
            }
            else{
                sum += prices[p];
            }
            p++;
        }
        
        return sum;
    }
};
