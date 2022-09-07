// Iterative way
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode* oddPtr = head, * evenPtr = head->next, * even_start = head->next;
        
        // This connects odd ones to odd ones & even ones to even ones
        while(oddPtr->next != NULL && evenPtr->next != NULL){
            oddPtr->next = evenPtr->next;
            evenPtr->next = oddPtr->next->next;
            
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        
        oddPtr->next = even_start;   //Place the first even node after the last odd node.
        
        return head;
        
    }
};