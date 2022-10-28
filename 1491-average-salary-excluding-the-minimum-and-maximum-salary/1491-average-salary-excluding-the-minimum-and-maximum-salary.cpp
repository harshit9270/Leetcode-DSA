class Solution {
public:
    double average(vector<int>& salary) {
        double avgSal = 0.0;
        int mini = INT_MAX, maxi = INT_MIN;
        int total = salary.size() - 2;
        
        for(int i : salary){
            mini = min(mini, i);
            maxi = max(maxi, i);
            
            avgSal += (double)i/total;
        }
        
        avgSal -= double(mini + maxi)/total;
        
        return avgSal;
    }
};