class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int m = p.length(), n = s.length();
        if (n < m)
            return ans;
        unordered_map<char, int> mp, ms;
        for (int i = 0; i < m; i++)
        {
            ms[s[i]]++;
            mp[p[i]]++;
        }
        for (int i = m; i < n; i++)
        {
            if (ms == mp)
                ans.push_back(i - m);
            // add next character
            ms[s[i]]++;
            // remove previous character
            ms[s[i - m]]--;
            if (ms[s[i - m]] == 0)
                ms.erase(s[i - m]);
        }
        if (ms == mp)
            ans.push_back(n - m);
        return ans;
    }
};