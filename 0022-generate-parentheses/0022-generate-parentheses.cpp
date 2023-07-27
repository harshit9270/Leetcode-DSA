class Solution {
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                //closing bracket
                if(!st.empty()){
                    char top = st.top();
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || 
                       (ch == ']' &&  top == '['))
                        st.pop();                        
                    else
                        return false;
                } 
                else
                    return false;
            }
        }
            
        return st.empty();
    }
public:    
    vector<string> generateParenthesis(int n) {
        string s(string(n,'(') + string(n,')')); 
        
        vector<string> ans;
        
        do{
            if(isValid(s))
                ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        
        return ans;
    }
};