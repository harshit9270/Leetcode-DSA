// Using Binary Search
class Solution {
public:
    int ceil(vector<int>&v, int l, int r, int x){
        int ans;
        
        while(l<=r){
            int mid=l+(r-l)/2;

            if(v[mid]>=x){
                ans = mid;
                r=mid-1;
            } 
            else 
                l=mid+1;
        }
        
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){

            if(nums[i]>v[v.size()-1]){
                v.push_back(nums[i]);
            }
            else{
                int idx=ceil(v,0,v.size()-1,nums[i]);
                v[idx]=nums[i];
            }
        }
        
        return v.size();
    }
};