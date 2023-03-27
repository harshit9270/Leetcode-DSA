// Bottom Up DP
class Solution {
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int index = n-1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int ans = 1e9;
                int prev1 = nums1[index-1], prev2 = nums2[index-1];

                if(swapped)
                    swap(prev1, prev2);

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index+1][1]);

                dp[index][swapped] = ans;
            }
        }
        
        return dp[1][0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        return solveTab(nums1, nums2);
    }
};