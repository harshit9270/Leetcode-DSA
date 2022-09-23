// Brute Force Approach
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7, length = 0;
        
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) 
                // to check if i is power of 2
                // for every power of 2, number of set bits increase by 1
                length++; 
            
            ans = ((ans << length) + i) % mod;
        }
        
        return ans;
    }
};