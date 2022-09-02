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
    void traverseLeaf(TreeNode* root, vector<int>& leaves){
        if(!root)
            return;
        
        if(!root->left && !root->right){
            leaves.push_back(root->val);
            return;
        }
        
        traverseLeaf(root->left, leaves);
        traverseLeaf(root->right, leaves);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        
        traverseLeaf(root1, leaves1);
        traverseLeaf(root2, leaves2);
        
        if(leaves1.size() != leaves2.size())
            return false;
        
        for(int i=0; i<leaves1.size(); i++){
            if(leaves1[i] != leaves2[i])
                return false;
        }
        
        return true;
    }
};