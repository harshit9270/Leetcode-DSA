class Solution {
public:
    // Using priority_queue
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
       
        // Using binary search to calculate the number of soldiers and number of civillians
        for(int i=0;i<mat.size();i++){
            int low=0,high=mat[0].size()-1,mid;
            while(low<=high){
                mid=low+(high-low)/2;
                if(mat[i][mid]==1)low=mid+1;
                else high=mid-1;
            }
            
            // Pushing the count of soldiers into queue with its row index
            pq.push({low,i});
            if(pq.size()>k)pq.pop();
        }
        
        vector<int>ans;
        
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};