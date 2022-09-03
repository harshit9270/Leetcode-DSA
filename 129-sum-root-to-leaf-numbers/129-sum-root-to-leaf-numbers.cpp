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
    // Using preorder traversal for traversing all paths
    void preOrder(TreeNode *root, int number, int & sumsOfPaths){
        if(!root)
            return;
        
        number = number*10 + root->val;
        
        if(!root->left && !root->right){
            sumsOfPaths += number;
            return;
        }
        
        preOrder(root->left, number, sumsOfPaths);
        preOrder(root->right, number, sumsOfPaths);        
    }
    
    int sumNumbers(TreeNode* root) {
        int sumsOfPaths = 0;
        
        preOrder(root, 0, sumsOfPaths);
        
        return sumsOfPaths;
    }
};





