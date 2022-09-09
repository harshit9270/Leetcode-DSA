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
    int levelX=-1;
    int levelY=-1;
    bool flag=true;

    bool isCousins(TreeNode* root, int x, int y) {
        levelfinder(root,x,y,0);
        
        return flag && levelX==levelY;
    }
    
    void levelfinder(TreeNode* root,int x,int y,int level){
        if(root==NULL) 
            return;
        
        if(root->left && root->right){
            if((root->left->val== x && root->right->val==y) ||
                (root->left->val==y && root->right->val==x))
                flag=false;
        }
        
        if(root->val==x) 
            levelX=level;
        else if(root->val==y) 
            levelY=level;
        
        levelfinder(root->left,x,y,level+1);
        levelfinder(root->right,x,y,level+1);
    }
};