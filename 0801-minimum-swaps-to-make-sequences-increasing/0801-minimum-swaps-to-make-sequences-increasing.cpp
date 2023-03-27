// Space Optimized DP Approach
class Solution {
    int solveSpaceOP(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        
        int swap = 0, noSwap = 0;
        int currSwap = 0, currNoSwap = 0;
        
        for(int index = n-1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int ans = 1e9;
                int prev1 = nums1[index-1], prev2 = nums2[index-1];

                if(swapped){
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noSwap;

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swap);

                if(swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swap = currSwap;
            noSwap = currNoSwap;
        }
        
        return min(swap, noSwap);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        return solveSpaceOP(nums1, nums2);
    }
};