// Sort nums in decreasing order so that instead of finding square of elements, we can find square root of elements. Then, we store frequency of each element in the hashmap. Then, we find perfect square root of each element (if exists) repeatedly until that element becomes a prime number.
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {  
        sort(nums.begin(), nums.end(), greater<int>());
        
        unordered_map<int, int> mp;
        for(int &i : nums)
            mp[i]++;
        
        int maxi=1;
        
        for(int i=0; i<nums.size(); i++){
            int count=1;
            int x=nums[i]; 
            
            while(mp[sqrt(x)]>0){
                int p=sqrt(x);
                //Since sqrt(x) can be a decimal number, check perfect square condition
                if(p*p==x) count++;
                else break;
                
                mp[sqrt(x)]--;
                x = sqrt(x);
            }
            maxi = max(maxi, count);
        }
        
        return maxi==1?-1:maxi;
    }
};