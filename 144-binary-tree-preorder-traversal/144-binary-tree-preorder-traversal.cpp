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
     //Using stack
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)
            return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            // Pick out the top node, put it in answer array
            TreeNode* currNode = st.top();
            st.pop();
            
            ans.push_back(currNode->val);
            
            // push the right child of the popped node into the stack
            if (currNode->right) {
                st.push(currNode->right);
            }

            // push the left child of the popped node into the stack
            if (currNode->left) {
                st.push(currNode->left);
            }

            // the right child must be pushed first so that the left child
            // is processed first (LIFO order)
        }
        return ans; 
    }
};