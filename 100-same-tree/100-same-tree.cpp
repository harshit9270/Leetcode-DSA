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
    // By matching preorder traversal
    void preorder(TreeNode* root, vector<int> & pre){
        if(!root){
            pre.push_back(-1);
            return;
        }
        
        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pre1, pre2;
        
        preorder(p, pre1);
        preorder(q, pre2);
        
        return pre1 == pre2;        
    }
};