// Bottom up DP
class Solution {
    int solveTab(vector<vector<char>>& matrix, int& maxi){
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;   
            }
        }
        
        return dp[0][0];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        
        solveTab(matrix, maxi);
        return maxi*maxi;
    }
};