//letcode 42
// optimal O(n) with O(1)space complexity

class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();

        // intialize left and right pointer
        int left = 0;
        int right = n-1;

        // initialize left and right max variables
        int left_max = 0;
        int right_max = 0;

        // initialize sum
        int sum = 0;

        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            
            // if left_max < rightmax
            if(left_max < right_max){
                sum = sum + left_max - height[left];
                left++;
            }
            else{
                sum = sum + right_max - height[right];
                right--;
            }

        }
        return sum;
    }
};




// O(n) with O(n) space complexity 

class Solution {
public:

    vector<int> get_leftMaxArray(vector<int>& height,int& n){
        vector<int> left_max(n);
        left_max[0] = height[0];

        for(int i = 1; i < n; i++){
            left_max[i] = max(left_max[i-1],height[i]);
        }
        return left_max;
    }

    vector<int> get_rightMaxArray(vector<int>& height,int& n){ // create fn
        vector<int> right_max(n);
        right_max[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--){
            right_max[i] = max(right_max[i+1],height[i]);
        }
        return right_max;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;

        vector<int> left_max = get_leftMaxArray(height,n);
        vector<int> right_max = get_rightMaxArray(height,n);

        for(int i = 0; i < n; i++){
            int h = min(left_max[i],right_max[i]) - height[i];
            sum += h;
        }
        return sum;
    }
};
