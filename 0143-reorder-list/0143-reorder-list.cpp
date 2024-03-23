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
class Solution {
public:
    // Brute Force Approach (Iterative)
    // TC -> O(n^2)
    void reorderList(ListNode* head) {
        // we need to find the penultimate node in order to proceed
        ListNode* penultimate;
        
        while (head && head->next && head->next->next) {
            penultimate = head;
            
            while (penultimate->next->next) 
                penultimate = penultimate->next;
            
            // then we move it in the second spot
            penultimate->next->next = head->next;
            head->next = penultimate->next;
            
            // and set penultimate to be the last
            penultimate->next = NULL;
            
            head = head->next->next;
        }
    }
};