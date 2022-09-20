class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) 
            return 0;
        
        // sort wrt the end point
        sort(points.begin(), points.end(),
            [](auto &a, auto &b) -> bool {
                return a[1] < b[1]; 
            });
        
        int burst_pt = points[0][1], arrows = 1;
        for(auto &point: points) {
            if(point[0] > burst_pt)
                ++arrows, burst_pt = point[1];
        }
        return arrows;
    }
};