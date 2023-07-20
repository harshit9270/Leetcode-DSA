// Using stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0)
                s.push(asteroids[i]);
            
            else{
                // asteroids[i] is negative
                if(!s.empty() && s.top() > 0){
                    if(abs(asteroids[i])>s.top()){
                        s.pop();
                        i--;
                    }
                    else if(abs(asteroids[i])==s.top())
                        s.pop();
                    
                    // else if(abs(asteroids[i]) < s.top())
                    //     continue;
                }
                else
                    s.push(asteroids[i]);                
            }
        }
        
        vector<int> res;
        while(!s.empty()){
            res.insert(res.begin() , s.top());
            s.pop();
        }
        
        return res;
        
    }
};