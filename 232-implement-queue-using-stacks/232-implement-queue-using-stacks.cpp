// Using 2 stacks
class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        
        int size = st.size();
        while(--size){
            temp.push(st.top());
            st.pop();
        }
        
        int elementToPop = st.top();
        st.pop();
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
        return elementToPop;
    }
    
    int peek() {
        stack<int> temp;
        
        int size = st.size();
        while(--size){
            temp.push(st.top());
            st.pop();
        }
        
        int elementAtTop = st.top();
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
        return elementAtTop;
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