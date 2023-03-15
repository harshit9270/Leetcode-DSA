// Bottom up DP
class Solution{
private: 
    bool solveTab(vector<int>&arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][target];
    }
    
public:
    bool canPartition(vector<int>& arr) {
        int total = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++)
            total += arr[i];
        
        if(total % 2 != 0) 
            return false;
        
        int target = total/2;
        
        return solveTab(arr, target);
    }
};