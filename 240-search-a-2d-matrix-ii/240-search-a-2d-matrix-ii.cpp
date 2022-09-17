// Using Binary Search
class Solution {
    
    // Any element to the right of matrix[i][j] will be greater than it
    // Any element to the top of matrix[i][j] will be smaller than it
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            int low = 0, high = matrix[i].size()-1;
            
            while(low <= high){
                int mid = low + (high-low)/2;
                
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target)
                    low = mid+1;
                else
                    high = mid-1;
            }            
        }
        
        return false;
    }
};