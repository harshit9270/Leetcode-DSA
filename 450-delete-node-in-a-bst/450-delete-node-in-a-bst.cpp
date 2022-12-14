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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) 
            return root;
        
        if(key < root->val) root->left = deleteNode(root->left, key);     
        //We recursively call the function until we find the target node
        
        else if(key > root->val) root->right = deleteNode(root->right, key);       
        
        else{      
            //No child condition
            if(!root->left && !root->right) 
                return NULL;    
            
            //One child contion -> replace the node with it's child
            if (!root->left || !root->right)
                return root->left ? root->left : root->right;    
            
            //Two child condition
            TreeNode *temp=root->left;
            while(temp->right)
                temp = temp->right;
            temp->right = root->right;
            return root->left;		
        }
        
        return root;
    }   
};