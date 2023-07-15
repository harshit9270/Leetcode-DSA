class Solution {
private:
    int findCount(vector<vector<int>> grid,int currRow,int totalCol){
        int start = 0;
        int end = totalCol-1;
        int count = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(grid[currRow][mid] < 0){
                count = max(totalCol - mid,count);
                end = mid - 1; // might be more number in back
            }
            else{
                start = mid + 1;
            }
        }
        return count;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int numberOfCol = grid[0].size();
        for(int i=0;i<grid.size();i++){
            int count = findCount(grid,i,numberOfCol);
            ans+=count;
        }
        return ans;
    }
};