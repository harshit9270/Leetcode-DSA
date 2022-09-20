// Greedy Approach
// Similar to Activity Selection Problem

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), cmp);
        
        int len = 1;
        int finishTime = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= finishTime){
                len ++;
                finishTime = intervals[i][1];
            }
        }
        
        return intervals.size() - len;
    }
};