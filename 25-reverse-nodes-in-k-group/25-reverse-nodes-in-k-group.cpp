// Simple and Concise
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != tail) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        
        for (int i = 0; i < k; i++) {
            if (!ptr) return head;
            ptr = ptr->next;
            
        }
        ListNode* tmp = reverse(head, ptr);
        head->next = reverseKGroup(ptr, k);
        return tmp;
    }
};