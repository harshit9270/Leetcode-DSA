// Space optimized DP
class Solution {
    int solveSO(vector<vector<char>>& matrix, int& maxi){
        int n = matrix.size(), m = matrix[0].size();
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;   
            }
            next = curr;
        }
        
        return next[0];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        
        solveSO(matrix, maxi);
        return maxi*maxi;
    }
};