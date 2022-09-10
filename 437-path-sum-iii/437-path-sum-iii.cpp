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
    long long int count=0;
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        
        return count;
    }
    
    void dfs(TreeNode* root, long long int sum){
        if(!root)
            return;
        
        if(root->val==sum)
            count++;
        
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};

