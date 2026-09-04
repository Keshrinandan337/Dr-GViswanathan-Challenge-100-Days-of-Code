//leetcode 4024
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans = -1;
        int min_distance = INT_MAX;
        
        for(int i = 0; i < n; i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            
            // calculate distance
            int distance = abs(x - target[0]) + abs(y - target[1]);
            if(distance <= range){
                if(distance < min_distance){
                    min_distance = distance;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
