class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto& t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();

                if(t == "+") a = b + a;
                if(t == "-") a = b - a;
                if(t == "/") a = b / a;
                if(t == "*") a = b * a;   
                s.push(a);
            }
            else 
                s.push(stoi(t));
        }

        return s.top(); 
    }
};