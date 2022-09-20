class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        
        int burst_pt = points[0][1], arrows = 1;
        
        for(auto &point: points) {
            if(point[0] > burst_pt)
                ++arrows, burst_pt = point[1];
        }
        
        return arrows;
    }
};