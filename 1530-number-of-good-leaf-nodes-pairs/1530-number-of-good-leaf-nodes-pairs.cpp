class Solution {
public:
    int ans = 0;
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
    
//Idea is to perform dfs & return a list of distances of all leaf nodes to the ancestor 
//and let the ancestor compare the distances of all it's leaf nodes, add them to result
    vector<int> dfs(TreeNode*root, int d){
        vector<int> p;
        if(!root) 
            return p;
        
        if(!root->left && !root->right)
            return {1};
        
        auto left = dfs(root->left, d);
        auto right = dfs(root->right, d);
        
        //Compare distance and add them to answer
        for(int i = 0; i<left.size(); i++)
            for(int j=0; j<right.size(); j++)
                if(left[i]+right[j] <=d )
                    ans ++;
        
        //Increase distance by one for all child and send them to parent
        for(int i=0; i<left.size(); i++)
            p.push_back(left[i]+1);
          
         for(int i=0; i<right.size(); i++)
            p.push_back(right[i]+1);
        
        return p;
    }
};