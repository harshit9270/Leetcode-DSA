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
    // Using level order traversal
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        bool flag=true;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto curr= q.front();
            q.pop();
            if(!curr)
                flag=false;
            else
            {
                // this condition will be reached if the flag was turned false at previous level than this, so there was a node missing in non-last level
                if(flag==false)
                    return false;
                    
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true;
    }
};