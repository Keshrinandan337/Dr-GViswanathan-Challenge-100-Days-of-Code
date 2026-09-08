//leetcode 452
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        vector<int> prev = points[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];

            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];

            if(currStartPoint > prevEndPoint){ // No Overlapping
                count++;
                prev = points[i];
            }
            else{ // Overlapping
                prev[0] = max(currStartPoint, prevStartPoint);
                prev[1] = min(currEndPoint, prevEndPoint);
            }
        }
        return count;
    }
};
