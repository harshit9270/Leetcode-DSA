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
    // Level order traversal
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        long long int levelSum = 0, nodeCount = 0;
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(!temp){
                averages.push_back((double)levelSum/nodeCount);
                if(!q.empty())
                    q.push(NULL);
                levelSum = 0;
                nodeCount = 0;
            }
            else{
                levelSum += temp->val;
                nodeCount++;
                
                if(temp->left)
                q.push(temp->left);
            
                if(temp->right)
                    q.push(temp->right); 
            }                       
        }
        
        return averages;
    }
};