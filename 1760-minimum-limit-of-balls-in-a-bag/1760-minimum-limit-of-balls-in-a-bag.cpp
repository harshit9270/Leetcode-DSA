class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 1e9;
        
        while(low < high){
            // mid is our bag limit. If it's 2, we can only split the bags into 
            // max balls of 2. So if we have a bag of 8 balls. We can split it into
            // 4 bags of 2 balls.
            int mid = low + (high - low) / 2;
            
            int splitOperations = 0;
            
            for(auto bag: nums)
                // subtracting 1 from bag before division to ensure both cases of odd and even are handled
                // 8/2 - 1 = 3, 7/2 - 1 = 2 
                splitOperations += (bag - 1)/mid;

            // if our split operations require more splits than allowed,
            // we can try reducing the number of splits by increasing
            // bag limit
            if(splitOperations > maxOperations)
                low = mid + 1;
            else 
            // if we're able to split bags into bag limit
            // and still not exceed the total allowed operations
            // we try to split even more bags by decreasing the bag limit
            // and see if we're able to split without exceeding the maximum
            // allowed split operations
                high = mid;
            
        }
        
        return low;
    }
};