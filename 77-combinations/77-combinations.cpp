// Recursive Approach
class Solution {
public:
    void help(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans){
        // If k is equal to 0, we have generated a Valid Subset of K length     
        if(k == 0){
            ans.push_back(subSet);
            return;
        }
        
        // If we don't have enough elements to make our subset, we shouldn't proceed further
        if(k > n-i+1)
            return;
        
        // If i becomes greater than N, we should stop going forward
        if(i>n)
            return;
        
        subSet.push_back(i);
        help(i+1, n, k-1, subSet, ans);
        
        //backtrack
        subSet.pop_back();
        help(i+1, n, k, subSet, ans);
    }
        
    vector<vector<int>> combine(int n, int k) {
        vector<int> subSet;
        vector<vector<int>> ans;
        
        help(1, n, k, subSet, ans);
        
        return ans;
    }
};