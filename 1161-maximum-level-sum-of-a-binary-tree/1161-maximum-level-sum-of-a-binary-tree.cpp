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
    int maxLevelSum(TreeNode* root) {
        int result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0, maxSum = INT_MIN, level = 1;
        
        while(!q.empty()){
            int size = q.size();
            
            //Level process
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }          
            
            if(sum > maxSum){
                maxSum =  sum;
                result = level;
            }
            
            sum = 0;
            level ++;
        }
        
        return result;
    }
};