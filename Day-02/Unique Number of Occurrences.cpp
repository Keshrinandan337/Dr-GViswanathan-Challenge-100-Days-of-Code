
// Leetcode question- 1207


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2001] = {0};   // Count for numbers -1000 to 1000


        // Count occurrences of each number using index
        for(int i = 0; i < arr.size(); i++){
            count[arr[i] + 1000]++;
        }

        // Sort the counts so we can check duplicates easily
        sort(count,count + 2001);

        // Check for any duplicate non-zero counts
        for(int i = 0 ; i < 2000; i++){
            if( count[i] != 0 && count[i] == count[i+1]){
                return false; // Duplicate frequency found
            }
        }
        return true;
    }
};
