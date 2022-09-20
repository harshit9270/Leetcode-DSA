// All the balloons need to bursted, so in worst case
// we can use N arrows and burst all. To optimize arrows
// we need to shoot at points with max number of intersecting
// balloons, but finding that makes the problem look very difficult.
// If we observe carefully and look at this sentence "All the balloons need to be burst",
// we can find a clue, since each balloon needs to burst anyway, we can shoot at its end point 
// and allow any balloons which also gets covered also be bursted. If we chose a point before the 
// end point then we might have missed a balloon intersection towards the end. 
// One important thing is to start wrt to the end pt and not start pt, that way we will
// know the extent till which a particular balloon can cover.

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