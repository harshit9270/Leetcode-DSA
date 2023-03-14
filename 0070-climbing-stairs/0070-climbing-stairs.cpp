// Space optimized DP
class Solution {
    int solve(int n){
        int prev2=1,prev1=1; // ** initally at 0th and 1st index
        
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
public:
    int climbStairs(int n) {        
        return solve(n);
    }
};