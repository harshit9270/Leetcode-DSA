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
    // Iterative Approach
    void postorder(TreeNode* root, vector<int> & post){
        if(!root)    
            return;
 
        // create an empty stack and push the root node
        stack<TreeNode*> s;
        s.push(root);
        
        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and push the data into the vector
            TreeNode* curr = s.top();
            s.pop();

            post.insert(post.begin(), curr->val);

            // push the left and right child of the popped node into the stack
            if (curr->left) {
                s.push(curr->left);
            }

            if (curr->right) {
                s.push(curr->right);
            }
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        
        postorder(root, post);
        
        return post;        
    }
};