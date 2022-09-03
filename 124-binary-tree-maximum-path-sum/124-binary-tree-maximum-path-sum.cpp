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

// I can do either either of the options presented:
// 1.I can choose to take up the left subtree or drop it.
// 2.I can either choose to take up the right subtree or drop it.
// 3.I check for a possibility whether if i were to take both left subtree and right subtree would that beat my current max_sum?
    
class Solution {
public:
    int max_sum=INT_MIN;
    
    int max_gain(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        
        //considering both left and right subtree along with root
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        
        // considering only maximum of left and right along with root
        return root->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};


