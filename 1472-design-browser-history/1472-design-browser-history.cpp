class BrowserHistory {
public:
    struct ListNode {
        string val;
        ListNode *prev, *next;
        ListNode() : val(""), prev(NULL), next(NULL) {}
        ListNode(string x) : val(x), prev(NULL), next(NULL) {}
        ListNode(string x,ListNode *prev, ListNode *next) : val(x), prev(prev), next(next) {}
    };
    
    ListNode *curr;
    
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage, NULL, NULL);
    }
    
    void visit(string url) {
        curr->next = new ListNode(url, curr, NULL);
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev != NULL){
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next != NULL){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */