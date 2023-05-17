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

// Brute Force (Linked List to Array)
class Solution {
public:
    int pairSum(ListNode* head) {
        // support variables
        vector<int> vals;
        int res = 0;
        // parsing the list
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        // checking the stored matches
        for (int i = 0, lmt = vals.size() / 2, j = vals.size() - 1; i < lmt; i++, j--) {
            res = max(res, vals[i] + vals[j]);
        }
        return res;
    }
};