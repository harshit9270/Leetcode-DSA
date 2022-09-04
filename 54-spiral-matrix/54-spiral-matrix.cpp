class Solution {
public:
    bool spiralSize(vector<int> &spiral, vector<vector<int>>& matrix){
        return (spiral.size() == matrix.size()*matrix[0].size());
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int i,k=0,l=0;
        int m = matrix.size(), n=matrix[0].size();
        int j=0;
        // k- starting row index
        // m- ending row index
        // l- starting column index
        // n- ending column index
        
        while(k<m && l<n){ 
            //this makes sure that there are elements in the matrix to be printed
            //Print first remaining row
            for(int i=l; i<n; i++){
                spiral.push_back(matrix[k][i]);
            }
            k++;
            if(spiralSize(spiral, matrix))
                break;
                
            //Print last remaining column
            for(int i=k; i<m; i++){
                spiral.push_back(matrix[i][n-1]);
            }
            n--;
            if(spiralSize(spiral, matrix))
                break;
            
            //Print last remaining row
            for(int i=n-1; i>=l; i--){
                spiral.push_back(matrix[m-1][i]);           
            }
            m--;
            if(spiralSize(spiral, matrix))
                break;
            
            //Print first remaining column
            for(int i=m-1; i>=k; i--){
                spiral.push_back(matrix[i][l]);
            }
            l++;
            if(spiralSize(spiral, matrix))
                break;
            
        }
        
        return spiral;
    }
};