// Two pointer approach
class Solution {
    
    // Any element to the right of matrix[i][j] will be greater than it
    // Any element to the top of matrix[i][j] will be smaller than it
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Starting from top-right corner (or start from bottom-left corner)
        
        int i=0, j=matrix[0].size()-1;
        
        while(i<matrix.size() && j>=0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        
        return false;
    }
};