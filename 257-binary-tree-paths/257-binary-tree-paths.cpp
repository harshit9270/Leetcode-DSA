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
    void preorder(TreeNode* root, string curr, vector<string> & output){
        if(!root)
            return;
        
        if(root->left || root->right)
            curr += to_string(root->val) + "->";
        else{
            curr += to_string(root->val);
            output.push_back(curr);
        }
        
        preorder(root->left, curr, output);
        preorder(root->right, curr, output);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        string curr = "";
        
        preorder(root, curr, output);
        
        return output;
    }
};