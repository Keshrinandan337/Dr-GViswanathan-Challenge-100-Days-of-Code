// leetcode 2007

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if (n % 2 != 0) { // check size is odd or even
            return {};
        }

        // sort array in ascending order
        sort(changed.begin(), changed.end());

        // create a map for storing frequency of each number
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[changed[i]]++;
        }

        vector<int> result;

        // Traverse the array

        for (int i = 0; i < n; i++) {
            int num = changed[i];
            int twise = 2 * num;

            if (mp[num] == 0) {
                continue; // skip
            }

            if (mp.find(twise) == mp.end() || mp[twise] == 0) {
                return {};
            }

            result.push_back(num);

            mp[num]--;
            mp[twise]--;
        }
        return result;
    }
};
