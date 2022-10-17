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
    bool solve(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return (solve(p->left, q->left) && solve(p->right, q->right));
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        
        return (solve(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};