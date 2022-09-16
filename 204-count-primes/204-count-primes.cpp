// Sieve of Eratosthenes Solution

// We start at 2 and for each number processed (num), we iterate through and mark each multiple (mult) of num, starting at num^2, as seen. We start at num^2 because every multiple up to the num'th multiple will have been guaranteed to have been seen before, since they're also a multiple of a smaller number. For example, when processing 5s, we can skip to 25 because 10 will have been seen when we processed 2s, 15 when we processed 3s, and 20 when we processed 2s.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seen(n, false);
        int ans = 0;
        for (int num = 2; num < n; num++) {
            if (seen[num]) continue;
            ans++;
            for (long mult = (long)num * num; mult < n; mult += num)
                seen[mult] = true;
        }
        return ans;
    }
};