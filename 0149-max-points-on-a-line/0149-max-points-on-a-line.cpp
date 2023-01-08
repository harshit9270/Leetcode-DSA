class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==2)
            return 2;
        int max_points = 0;
        
        for(int i=0; i<points.size(); i++){
            unordered_map <double, int> map;
            
            for(int j=i+1; j<points.size(); j++){
                if((points[i][0] - points[j][0]) != 0){
                    double m = ((points[i][1]-points[j][1]) * 1.0)/ (points[i][0]-points[j][0]);
                    map[m]++; 
                    
                    max_points = max(max_points, map[m]);
                }
                else{
                    map[INT_MAX]++;
                    
                    max_points = max(max_points, map[INT_MAX]);
                }
            }
        }
        
        return max_points+1;
    }
};