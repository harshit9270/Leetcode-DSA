// Greedy Approach
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        
        unordered_map<int,int> freq;
        for(int i : tasks)
            freq[i]++;
        
        for(auto it : freq){
            int k = it.second;
            if(k == 1)
                return -1;
            if(k%3 == 0)
                ans += k/3;
            else // k%3 gives 2 here, adding 1 extra for the round in which 2 tasks will be done
                ans += (k/3)+1;
        }
        
        return ans;
    }
};