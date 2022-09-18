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

// Using Set + Extra Space
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //multiset allows duplicate entries and stores in sorted order
        multiset<int> s;
        
        for(auto list : lists){
            while(list){
                s.insert(list->val);
                list = list->next;
            }
        }
        
        ListNode* head = new ListNode;
        ListNode* temp = head;
        
        for(int i : s){
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        
        return head->next;
    }
};