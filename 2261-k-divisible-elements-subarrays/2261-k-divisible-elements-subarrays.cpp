class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), res = 0;
        unordered_set<string> all; 
        
        for (int i=0; i<n; i++) {
            int cnt = 0;
            string currSubArray; // stores subarray starting from index i
            
            for (int j=i; j<n; j++) {
                // Appending charcter with nums[j] ascii value
                currSubArray.push_back(nums[j]); 
                
                if (nums[j] % p == 0)  
                    cnt++;    
                
                // if the current array have at most k elements divisible by p, add it to the set
                if (cnt <= k)    
                    all.insert(currSubArray);
            }
        }
        
        return size(all);
    }
};