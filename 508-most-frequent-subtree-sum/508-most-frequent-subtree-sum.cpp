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

// Using hashmap

class Solution {
public:
    int helper(TreeNode *root, map<int, int> &mp){
        if(!root)
            return 0;
        
        int sum = root->val;
        
        int left = helper(root->left, mp);
        int right = helper(root->right, mp);
        
        sum += left + right;
        mp[sum]++;
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode *root){
        map<int, int> mp;
        helper(root, mp);
        vector<int> v;
		
        int mx = -1;
		//mx is the sum that appears maximum time, 
        // if there are multiple sums with maximum count, then push them in vector.
        
        for(auto it : mp){
            if(it.second > mx){
                v.clear();
                mx = it.second;
                v.push_back(it.first);
            }
            else if (it.second == mx)
                v.push_back(it.first);
        }
        
        return v;
    }
};