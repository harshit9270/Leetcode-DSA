// Top down DP
class Solution{
private: 
    bool solveMemo(vector<int>&arr, int target, vector<vector<int>>& dp, int index, int sum){
        int n = arr.size();
        if(index >= n || sum > target) 
            return false;
        if(sum == target) 
            return true;
        
        if(dp[index][sum] != -1)
            return dp[index][sum];
        
        bool take = solveMemo(arr, target, dp, index+1, sum+arr[index]);
        bool nottake = solveMemo(arr, target, dp, index+1, sum);
        
        dp[index][sum] = (take || nottake);
        return dp[index][sum];
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
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solveMemo(arr, target, dp, 0, 0);
    }
};