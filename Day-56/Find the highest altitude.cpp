//leetcode 1732
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int output = 0;
        int altitude = 0;
        for(int i = 0; i < n; i++){
            if(gain[i] < 0){
                altitude = altitude + gain[i];
                output = max(output, altitude);
            }
            else if(gain[i] > 0){
                altitude = altitude + gain[i];
                output = max(output, altitude);
            }
            else{
                continue;
            }
        }
        return output;
    }
};
