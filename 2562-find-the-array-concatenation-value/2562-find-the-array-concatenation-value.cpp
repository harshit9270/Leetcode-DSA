class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        
        if(n==1) return nums[0];
        
        long long i=0,j=n-1;
        while(i<j){
            string s=to_string(nums[i]) + to_string(nums[j]);
            
            ans += stoi(s);
            i++;
            j--;
        }
        
        if(i==j) ans += nums[i];
        return ans;
        
    }
};