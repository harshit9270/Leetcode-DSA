// Sliding Window Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        
        int left = 0;
        int right = 1;
        
        int maxPro = 0;
        
        while(right < prices.size()){
            if(prices[left] > prices[right]){
                left = right;
                right ++;
            }
            else{
                maxPro = max(maxPro, prices[right] - prices[left]);
                right++;
            }
        }
        
        return maxPro;
    }
};