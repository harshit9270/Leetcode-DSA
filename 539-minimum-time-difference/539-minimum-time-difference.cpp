class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time(n, 0);
        
        for(int i = 0; i < n; i++){
            string str = timePoints[i];
            
            int hour = stoi(str.substr(0, 2));
            int min = stoi(str.substr(3, 2));
            
            time[i] = hour * 60 + min;
        }
        
        sort(time.begin(), time.end());
        
        int mini = INT_MAX;
    
        for(int i = 0; i < n - 1; i++){
            int diff = time[i + 1] - time[i];
            
            mini = min(mini, diff);
        }
        
        mini = min(mini, (time[0] + 24 * 60) - time[n - 1]);
        
        return mini;
    }
};