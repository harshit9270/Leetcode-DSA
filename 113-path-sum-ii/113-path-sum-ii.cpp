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
    void solve(TreeNode* root, int targetSum, vector<int>curr, vector<vector<int>>& list){
        //Preorder Traversal
        if(!root)
            return ;
        
        if(!root->left && !root->right && root->val - targetSum == 0){
            curr.push_back(root->val);
            list.push_back(curr);
            return ;            
        }
        
        curr.push_back(root->val);
        solve(root->left,targetSum - root->val, curr, list);
        solve(root->right,targetSum - root->val, curr, list);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> list;
        solve(root, targetSum, {}, list);
        
        return list;
    }
};