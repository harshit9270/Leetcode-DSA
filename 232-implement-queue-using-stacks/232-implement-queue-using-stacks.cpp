// Using 2 stacks
// Roles reversed (using costly operation for push, so that pop & peek are cheap)
class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int topElement = st.top();
        st.pop();
        
        return topElement;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */