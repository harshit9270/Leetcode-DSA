class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        
        q.push(x);
    }
    
    int pop() {
        
         // 1 2 3
        // 1 2
    
        queue<int> q2;
        int size = q.size();
        int top = q.back();
        
        size--;
        
        while(size--)
        {
            
            q2.push(q.front());
            q.pop();
            
            
            
        }
        
        q = q2;
        
        return top;
        
        
        
    }
    
    int top() {
        
            return q.back();
            
            
    }
    
    bool empty() {
        return q.empty();
        }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */