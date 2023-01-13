class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), res = 1;
        vector<int> cnt(n), top1(n, 1), top2(n, 1);
        for (int i = 1; i < n; ++i)
            ++cnt[parent[i]];
        queue<int> q;
        for (int i = 1; i < n; ++i)
            if (cnt[i] == 0)
                q.push(i);
        while (!q.empty() && q.front() != 0) {
            int i = q.front(), p = parent[i]; 
            q.pop();
            if (int length = 1 + (s[i] != s[p] ? top1[i] : 0); top1[p] <= length) {
                top2[p] = top1[p];
                top1[p] = length;
            }
            else
                top2[p] = max(top2[p], length);
            if (--cnt[p] == 0) {
                q.push(p);
                res = max(res, top1[p] + top2[p] - 1);
            }
        }
        return res;
    }
};