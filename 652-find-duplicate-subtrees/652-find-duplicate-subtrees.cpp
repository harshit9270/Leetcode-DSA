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
    vector<TreeNode*> ans;
    unordered_map<string, int> mymap;
    
    string helper(TreeNode* root){
        if(root == NULL) return "";

        string l= helper(root->left);
        string r= helper(root->right);
        
        //make unique string of each subtree
        string s = "(" + l + to_string(root->val) + r + ")"; 

        // if string is not present insert and increase count
        if(mymap[s]!=-1) mymap[s]++; 
      
        if(mymap[s]>1) // if same string found more than one time we got same subtrees
        {
          ans.push_back(root);
          mymap[s]=-1; // no need to insert again
        }

        return s; 
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
};