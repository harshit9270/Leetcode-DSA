// Greedy Approach
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // support variables
        int curr = 0, total = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            
            curr += gain;
            total += gain;
            
            if (curr < 0) {
                start = i+1;
                curr = 0;
            }
        }
        
        return total >= 0 ? start : -1;
    }
};