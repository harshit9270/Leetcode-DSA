// Using stack
// similar to next greater element

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        
        vector<int> answer(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = temperatures[i];
            
            while(!s.empty() && temperatures[s.top()] <= curr)
                s.pop();
            
            if(!s.empty())
                answer[i] = s.top()-i;
            s.push(i);
        }
        
        return answer;
    }
};