/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// Linked List -> Vector -> BST

class Solution {
    void llToVector(ListNode* head, vector<int> & vec){
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
    }
    
    TreeNode* vectorToBST(vector<int> & vec, int start, int end){
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        TreeNode* head = new TreeNode(vec[mid]);
        
        head->left = vectorToBST(vec, start, mid-1);
        head->right = vectorToBST(vec, mid+1, end);
        
        return head;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        llToVector(head, vec);
        
        int n = vec.size();
        return vectorToBST(vec, 0, n-1);
    }
};









