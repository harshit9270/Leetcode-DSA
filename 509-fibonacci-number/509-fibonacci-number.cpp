// Using DP

class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int prev = 1;
        int prev2 = 0;
        int ans = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};