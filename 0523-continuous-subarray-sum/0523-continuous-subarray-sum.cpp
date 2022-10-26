// Traverse through the array and -

// 1. Calculate running sum and take the modulus of it from k ;
// 2. If not already present in hash map , then insert in hash map.
// 3. See if it is already present in the hash map but atleast , 2 position before so that we will get the size of subarray >=2.
// CONCEPT : You will encounter the same 'sum%k' , only if the previous 'sum%k' plus some multiple of k is there within this range . So it will have a subarray satifying the criteria .
    
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefSum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            prefSum += nums[i];
            prefSum %= k;

            if(prefSum == 0 && i) 
                return true;
            
            if(mp.find(prefSum) != mp.end()){
                // check if atleast 2 elements are there or not
                if(i - mp[prefSum] > 1) 
                    return true; 
            }
            else 
                mp[prefSum] = i;
        }

        return false;
    }
};