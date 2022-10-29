// Greedy Approach
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int max_bloom_time = INT_MIN;
        vector<pair<int,int>> data;
        
        for(int i=0; i<plantTime.size(); i++)
            data.push_back({growTime[i], plantTime[i]});
        
        // sorting decreasing order
        sort(data.begin(), data.end(), greater<pair<int,int>>());
        
        int prev_plant_time = 0;
        
        for(int i=0; i<data.size(); i++) {
            int grow_time = data[i].first; 
            int plant_time = data[i].second; 
        
            prev_plant_time += plant_time; 
            
            int bloom_time = prev_plant_time + grow_time + 1; 
            
            max_bloom_time = max(max_bloom_time, bloom_time);
        }
        
        return max_bloom_time - 1; 
    }
};