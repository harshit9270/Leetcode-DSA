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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, * fast = head;
        // this moves the fast pointer ahead n-1 times
        while(n--)
            fast = fast->next;
        
        // when n is the same as the length of the list
        if (!fast) return head->next;
        
        // this moves the slow pointer ahead (listLength/2) times
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        // Now slow pointer contains the refernce to the previous pointer of kth from end
        ListNode* toDelete = slow->next;
        
        slow->next = slow->next->next;
        
        delete toDelete;
        
        return head;
        
    }
};