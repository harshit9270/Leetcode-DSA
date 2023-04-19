/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    void solve(TreeNode* root, int dir, int currLength, int &maxLength){
        if(!root) 
            return;
        maxLength = max(maxLength, currLength);
        
        solve(root->left, 0, dir ? currLength+1 : 1, maxLength);
        solve(root->right, 1, dir ? 1 : currLength+1, maxLength);
    }

    int longestZigZag(TreeNode* root) {
        int maxLength = 0;
        
        solve(root, 0, 0, maxLength);
        solve(root, 1, 0, maxLength);
        
        return maxLength;
    }
};