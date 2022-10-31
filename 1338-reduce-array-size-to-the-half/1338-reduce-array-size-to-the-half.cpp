class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;    
        priority_queue<int> pq;       //max heap

        for(auto it:arr) 
            mp[it]++;    
        
        for(auto it:mp) 
            pq.push(it.second);
            
        int ele=0, setCount=0;
        
        while(!pq.empty()){    
            ele+=pq.top();     
            pq.pop();          
            
            setCount++;

            if(ele>=n/2) return setCount;
        }
        
        return 0;
    }
};