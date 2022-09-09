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
    int maxDiff = 0;
    
    // Using preorder to traverse through all paths
    void preorder(TreeNode* root, vector<int> pre){
        if(!root)
            return;
        
        pre.push_back(root->val);
        
        // when reach to a leaf node, examine for all possible values for maxDiff in pre array
        if(!root->left && !root->right){
            for(int i=0; i<pre.size()-1; i++){
                for(int j=i+1; j<pre.size(); j++){
                    maxDiff = max(maxDiff, abs(pre[i]-pre[j]));
                }
            }
        }
        
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        preorder(root, {});
        
        return maxDiff;
    }
};