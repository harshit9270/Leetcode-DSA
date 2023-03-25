// Space Optimized DP Approach
class Solution{
private: 
    bool solveTab(vector<int>&arr, int total){
        int n = arr.size();
        vector<int> curr(total/2 +1, 0);
        vector<int> next(total/2 +1, 0);
        
        curr[0] = 1; next[0] = 1;
        
        for(int index = n-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = next[target - arr[index]];
                
                bool excl = next[target];
                
                curr[target] = incl or excl;
            }
            next = curr;
        }
        
        return next[total/2];
    }
    
public:
    bool canPartition(vector<int>& arr) {
        int total = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++)
            total += arr[i];
        
        if(total % 2 != 0) 
            return false;
        
        return solveTab(arr, total);
    }
};