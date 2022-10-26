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
    TreeNode* treeHelper(vector<int>v,int s, int e){
        if(s>e)
            return 0;
        
        int maxi = -1, index;
        
        for(int i=s; i<=e; i++){
            if(v[i]>maxi){
                maxi = v[i];
                index = i;
            }
        }
        
        TreeNode* root = new TreeNode(maxi);
        root->left = treeHelper(v,s,index-1);
        root->right = treeHelper(v,index+1,e);
        
        return root;
    }
public:    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        return treeHelper(nums,0,nums.size()-1);
    }
};