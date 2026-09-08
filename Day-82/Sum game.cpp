//leetcode 1927
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left_Qn_Marks = 0;
        int right_Qn_Marks = 0;

        int left_Known_Sum = 0;
        int right_Known_Sum = 0;

        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    left_Qn_Marks++;
                }
                else{
                    right_Qn_Marks++;
                }
            }
            else{
                if(i < n/2){
                    left_Known_Sum += num[i] - '0';
                }
                else{
                    right_Known_Sum += num[i] - '0';
                }     
            }
        }

        int total_Qn_Marks = left_Qn_Marks + right_Qn_Marks;

        if(total_Qn_Marks % 2 == 1){ // odd question marks alsways alice win
            return true;
        }

        int LeftSide = 2 * left_Known_Sum + 9 * left_Qn_Marks;
        int RightSide = 2 * right_Known_Sum + 9 * right_Qn_Marks;

        if(LeftSide == RightSide){ // Bob wins
            return false;
        }
        else{
            return true;
        }
    }
};
