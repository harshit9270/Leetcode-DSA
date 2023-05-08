// Using stack
class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() or minStack.top() >= val)
            minStack.push(val);
    }
    
    void pop() {
        if(mainStack.top()==minStack.top())
            minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */