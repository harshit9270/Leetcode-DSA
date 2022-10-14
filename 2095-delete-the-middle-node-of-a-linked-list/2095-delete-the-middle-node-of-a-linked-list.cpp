// Two pointers Approach (slow and fast)
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            delete head;
            return NULL;
        }
        ListNode* slow = head, * fast = head;
        ListNode* prev = head; // keeping this prev node to get the previous node of slow pointer when we reach middle
        
        // Store the node before the middle node in slow
        while(fast != NULL && fast->next != NULL){
            if(slow != head) prev = prev->next; // since we want prev to start one step later than slow node
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* toDelete = prev->next;
        prev->next = prev->next->next;
        
        delete toDelete;
        
        return head;
    }
};