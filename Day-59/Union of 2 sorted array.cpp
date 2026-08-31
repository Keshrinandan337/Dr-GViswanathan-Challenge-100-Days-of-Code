//Geeks of geeks 
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j = 0;
        
        vector<int> ans;
        
        while(i < n && j < m){
            if(a[i] < b[j]){
                if(ans.empty() || ans.back() != a[i]){
                    ans.push_back(a[i]);
                }
                i++;
            }
            else if(a[i] > b[j]){
                if(ans.empty() || ans.back() != b[j]){
                    ans.push_back(b[j]);
                }
                j++;
            }
            else if(a[i] == b[j]){
                if(ans.empty() || ans.back() != b[j]){
                    ans.push_back(b[j]);
                }
                i++;
                j++;
            }
        }
        
        while(i<n){
            if(ans.empty() || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
            i++;            
        }

        while(j<m){
            if(ans.empty() || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;            
        }
        return ans;
    }
};
