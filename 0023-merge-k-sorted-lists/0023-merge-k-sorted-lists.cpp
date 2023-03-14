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

// Using priority queue

class cmp{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        priority_queue<ListNode* , vector<ListNode*>, cmp> pq;
        
        for(ListNode* l : lists)
            if(l)
                pq.push(l);
        
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        
        while(! pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            
            if(curr->next)
                pq.push(curr->next);
            
            ptr->next = curr;
            ptr = ptr->next;            
        }
        
        return head->next;
    }
};












