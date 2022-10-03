// Greedy Approach
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = 0;
        int ans = 0;

        for(int i =1; i<colors.size();i++){
            // if previous balloon is not same as current, update previous to current and continue
            if(colors[i]!=colors[prev]) 
            {
                prev = i;
                continue;
            }
            
            // if current and previous are same, add minimum time from current & previous to answer
            else
                ans+=min(neededTime[prev], neededTime[i]); 

            // if previous balloon is removed then new prev is current balloon
            // else if current balloon is removed then prev stays the same, no need to update

            if(neededTime[prev] < neededTime[i]) 
                prev = i;
        }
        
        return ans;   
    }
};