//leetcode 50
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(n == 0) return 1.0;
        if(x == -1 && n%2==0) return 1.0;
        if(x == -1 && n%2!=0) return -1.0;

        long binaryform = n; // for n = 5 binaryform is 101
        if(n < 0){
            x = (1/x);
            binaryform = - binaryform;
        }
        double ans = 1;
        while(binaryform > 0){
            if(binaryform % 2 == 1){
                ans *= x;
            }
            x *= x;
            binaryform = binaryform >> 1;
        }
        return ans;
    }
};
