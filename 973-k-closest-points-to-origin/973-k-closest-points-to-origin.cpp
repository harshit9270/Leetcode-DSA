// Using priority queue
typedef pair<double, vector<int>> piv;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<piv, vector<piv>> pq;
        
        for(int i=0; i<k; i++){
            double distance = pow((points[i][0]*points[i][0] + points[i][1]*points[i][1]), 0.5);
            
            pq.push(make_pair(distance, points[i]));
        }
        
        for(int i=k; i<points.size(); i++){
            double distance = pow((points[i][0]*points[i][0] + points[i][1]*points[i][1]), 0.5);
            
            if(pq.top().first > distance){
                pq.pop();
                pq.push(make_pair(distance, points[i]));
            }
        }
        
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};