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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        ListNode* res = new ListNode;
        ListNode* head = res;
            
        while(list1 && list2){
            if(list1 -> val < list2 -> val){
                res -> next = list1;
                res = res->next;
                list1 = list1->next;
            }
            else{
                res -> next = list2;
                res = res->next;
                list2 = list2->next;
            }
        }
        
        if(list1)
            res->next = list1;
        
        if(list2)
            res->next = list2;
        
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        
        return head;
    }
};