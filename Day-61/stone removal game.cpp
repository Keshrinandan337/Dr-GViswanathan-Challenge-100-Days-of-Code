//letcode 3360
class Solution {
public:
    bool canAliceWin(int n) {
        int stone = 10;
        int turn = 0;
        while(n >= stone){
            n -= stone;
            stone--;
            turn++;
        }
        if(turn % 2 == 1){
            return true;
        }
        return false;
    }
};
