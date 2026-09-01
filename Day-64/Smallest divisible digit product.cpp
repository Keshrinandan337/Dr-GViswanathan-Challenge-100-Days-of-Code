//leetcode 3345
class Solution {
public:
    int n_product(int n){
        int product = 1;
        while(n > 0){
            int element = n % 10;
            product = product * element;
            n /= 10; 
        }
        return product;
    }
    
    int smallestNumber(int n, int t) {
        while(n>0){
            int product = n_product(n);

            if(product % t == 0){
                return n;
            }
            n++;
        }
        return 0;
    }
};
