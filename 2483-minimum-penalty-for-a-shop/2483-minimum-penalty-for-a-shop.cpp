class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        int bestTime = 0, maxProfit = 0;
        pair<int, int> cnt = {0, 0}; // <net_profit, bestTime>
        
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                cnt.first ++;
                cnt.second = i+1;
            }
            else{
                cnt.first --;
                cnt.second = i;
            }
            
            if(cnt.first > maxProfit)
                bestTime = cnt.second;
            
            maxProfit = max(maxProfit, cnt.first);
        }
        
        return bestTime;
    }
};