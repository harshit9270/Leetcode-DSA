// Recursive way
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
    // Using same approach as that for reverse k nodes by fixing k=2
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* prevPtr = NULL, *currPtr = head, *nextPtr;
        
        int count=0;
        // Swap 2 nodes starting from head
        while(currPtr != NULL && count < 2){
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            
            prevPtr = currPtr;
            currPtr = nextPtr;
            count++;
        }
        
        // if nodes left for swapping, recursively call for swap with nextPtr as new head
        if(nextPtr != NULL)
            head->next = swapPairs(nextPtr);
        
        return prevPtr;
    }
};