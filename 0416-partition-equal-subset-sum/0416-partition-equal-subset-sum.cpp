// Bottom up DP
class Solution{
private: 
    bool solveTab(vector<int>&arr, int total){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(total/2 +1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int index = n-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = dp[index+1][target - arr[index]];
                
                bool excl = dp[index+1][target];
                
                dp[index][target] = incl or excl;
            }
        }
        
        return dp[0][total/2];
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