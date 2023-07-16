// Using extra space
// TC -> O((n1+n2)log(n1+n2))
// SC -> O(n1+n2)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3(nums1.size()+nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
        
        return (nums3.size()%2 == 1) ? (double)nums3[nums3.size()/2] : (nums3[nums3.size()/2] + nums3[nums3.size()/2 - 1])/2.0;        
    }
};