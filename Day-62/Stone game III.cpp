//leetcode 1406
class Solution {
public:
    vector<int> t;
    int solve(vector<int>& stones,int i){

        if(i >= n){ 
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = stones[i] - solve(stones,i+1); // 0th stone condition

        if(i+1 < n)
            result = max(result,stones[i] + stones[i+1] - solve(stones,i+2));

        if(i+2 < n)   
            result = max(result,stones[i] + stones[i+1] +stones[i+2] - solve(stones,i+3));

        return t[i] = result;
    }
    int n;
    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        t.resize(n+1,-1);
        int diff = solve(stones,0);// difference bw alice and bob

        if(diff > 0){
            return "Alice";
        }
        else if(diff < 0){
            return "Bob";
        }
        return "Tie";
    }
};
