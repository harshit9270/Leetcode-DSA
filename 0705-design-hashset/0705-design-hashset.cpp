class MyHashSet {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(NULL) {}
        ListNode(int x) : val(x), next(NULL) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* head;
    
    MyHashSet() {
        head = new ListNode(-1);
    }
    
    void add(int key) {
        ListNode* temp = new ListNode(key);
        ListNode* curr = head;
        while(curr and curr->next) {
            if(curr->next->val == key)    return;
            curr = curr->next;
        }
        curr->next = temp;
    }
    
    void remove(int key) {
        ListNode* temp = head;
        while(temp and temp->next) {
            if(temp->next->val == key)
                temp->next = temp->next->next;
            temp = temp->next;
        }
    }
    
    bool contains(int key) {
        ListNode* temp = head;
        while(temp) {
            if(temp->val == key)    return true;
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */