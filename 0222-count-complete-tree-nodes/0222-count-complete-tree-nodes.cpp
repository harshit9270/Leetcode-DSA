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
// Using Level Order Traversal 
// O(h)
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        if(!root)
            return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            
            count ++;
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        
        return count;
    }
};