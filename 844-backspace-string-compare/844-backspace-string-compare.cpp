class Solution {
public:
    // Using 2 stacks
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '#'){
                if(!st1.empty())
                    st1.pop();
            }
            else
                st1.push(s[i]);
        }
        for(int i=0; i<t.length(); i++){
            if(t[i] == '#'){
                if(!st2.empty())
                    st2.pop();
            }
            else
                st2.push(t[i]);
        }
        
        if(st1.size() != st2.size())
            return false;
        
        while(!st1.empty()){ // both the stacks are same size
            if(st1.top() != st2.top())
                return false;
            
            st1.pop();
            st2.pop();
        }
        
        return true;
    }
};