class Solution {
public:
    // Using binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size() * matrix[0].size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            pair<int, int> midElement = make_pair(mid/matrix[0].size(), mid%matrix[0].size());
            
            if(matrix[midElement.first][midElement.second] == target)
                return true;
            else if(matrix[midElement.first][midElement.second] < target)
                start = mid+1;
            else
                end = mid-1;              
        }
        
        return false;        
    }
};