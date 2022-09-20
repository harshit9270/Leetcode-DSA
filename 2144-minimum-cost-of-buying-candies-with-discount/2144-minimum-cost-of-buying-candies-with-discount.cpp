// Greddy Approach

// Simply sort the array and iterate from last.
// Take the last 2 costs & skip the next one, because we’ll get free if it’s equal or less than the minimum one.
// Reduce the index by 3 to skip an element i = i-3
// If i became 1 or 0 then return ans else we need to add the first element of the array because we won’t get that free.
// Time complexity: O(nlogn).
    
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int mini = 0;
        
        if(cost.size() <= 2){
            for(auto x: cost) 
                mini += x;
            return mini;
        }
        
        sort(cost.begin(), cost.end());
        
        int buy = cost.size()-1;
        
        while(buy >= 1){
            mini = mini + cost[buy] + cost[buy-1];
            
            if(buy-1 == 0 || buy-1 == 1)
                return mini;
            
            buy -= 3;
        }
        
        mini += cost[0];
        
        return mini;
    }
};