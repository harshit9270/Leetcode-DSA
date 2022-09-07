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
    // Using inorder traversal
    void inorder(TreeNode* root, vector<int> & vec) {
        if (!root) 
            return;
        
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        
        int min_diff = INT_MAX;
        int i = 0;
        while (i < vec.size()-1) {
            min_diff = min(min_diff, abs(vec[i] - vec[++i]));
        }
        
        return min_diff;
    }
};