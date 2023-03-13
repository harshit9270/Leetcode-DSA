// Using priority queue
typedef pair<int, int> pi;

class cmp{
public:
    bool operator()(pi& a, pi&b){
        if(a.second == b.second)
            return a.first > b.first;
        else 
            return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi, vector<pi>, cmp> pq;
        
        for(int i : arr)
            pq.push({i, abs(i-x)});
        
        vector<int> res;
        while(k--){
            auto curr = pq.top();
            pq.pop();
            
            res.push_back(curr.first);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};