/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // By matching the value of nodes in cloned with value of target
    // Level order traversal of cloned
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode *> q;
        q.push(cloned);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->val == target->val)
                return temp;
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);            
        }
        
        return NULL;
    }
};