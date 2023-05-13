class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> res(200005, 0);
        set<int> s;
        
        for(int i=0; i<10; i++)
            s.insert(i);
        
        long long mod = 1000000007;
        res[0] = 1;
        
        for(int i=0; i<100005; i++){
            res[i + zero] %= mod;
            res[i + zero] += res[i];
            res[i + one] %= mod;
            res[i + one] += res[i];
        }
        
        long long ans = 0;
        for(int i=low; i <= high; i++)
            ans = (ans + res[i]) % mod;
        
        return ans;
    }
};