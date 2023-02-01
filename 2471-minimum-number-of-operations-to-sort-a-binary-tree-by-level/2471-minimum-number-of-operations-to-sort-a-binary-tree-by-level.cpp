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
    int getMinimumSwaps(vector<int> & A) {
        int n = A.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i].first = A[i];
            vec[i].second = i;
        }
        
        sort(vec.begin(), vec.end());
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i].second == i)
             continue;

            swap(vec[i],vec[vec[i].second]);
            i--;

            ++cnt;      
        }
        
        return cnt;
    }
public:
    // Using level order traversal
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        int ans = 0;
        
        while(! q.empty()){
            int sz = q.size();
            vector<int> arr;
            
            for(int i=0; i<sz; i++){
                TreeNode * ptr = q.front();
                q.pop();
                
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
                
                arr.push_back(ptr->val);
            }
                
            ans += getMinimumSwaps(arr);
        }
        
        return ans;
    }
};