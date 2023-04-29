// Using extra space
// TC -> O((n1+n2)log(n1+n2))
// SC -> O(n1+n2)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        
        for(int i : nums1)
            nums3.push_back(i);
        for(int i : nums2)
            nums3.push_back(i);
        
        sort(nums3.begin(), nums3.end());
        
        return (nums3.size()%2 == 1) ? (double)nums3[nums3.size()/2] : (nums3[nums3.size()/2] + nums3[nums3.size()/2 - 1])/2.0;        
    }
};