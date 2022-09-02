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


// pattern ye h ki apan sbse pehle tree ki rightmost root pr jaayenge
// uske root se climb krte chlenge upr ki trf aur root ki value ko sum k euqal krte chlenge

class Solution {
public:
    int sum =0;
    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root)return 0;
        bstToGst(root->right); // rightmost root tk pahucnge
        sum+=root->val;
        root->val = sum; // right se top pr chd rhe h apan
        bstToGst(root->left); // left ki aur chl rhe h
        return root;
        
        
    }
};