class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        queue<TreeNode*> q; 
        q.push(root); 
        
        int count = 1; //since depth starts from 1 
        
        while(!q.empty()) 
        {
            int n = q.size(); 
            count++; 
            
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop(); 
                
                // if we not reach till our required level
                // so we have to do nothing, simply push into queue
                if(count != depth) {
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                }
                else { 
                    TreeNode* newNode = new TreeNode(val);
                    newNode -> left = curr -> left;
                    
                    curr -> left = newNode;
                    
                    TreeNode* newNode2 = new TreeNode(val);
                    newNode2 -> right = curr -> right;
                    
                    curr -> right = newNode2;
                }
            }
        }

        return root; 
    }
};