// When the elements are the same as the candidate element, votes are incremented when some other element is found not equal to the candidate element. We decreased the count. This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that if the candidate is a majority it occurs more than N/2 times and the remaining elements are less than N/2. We keep decreasing the votes since we found some different element than the candidate element. When votes become 0, this actually means that there are the same number of different elements, which should not be the case for the element to be the majority element. So the candidate element cannot be the majority, so we choose the present element as the candidate and continue the same till all the elements get finished. The final candidate would be our majority element. We check using the 2nd traversal to see whether its count is greater than N/2. If it is true, we consider it as the majority element.

class Solution {
public:
    // MOORE'S VOTING ALGORITHM
    int majorityElement(vector<int>& nums) {
        int majority,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if (count == 0)
                majority = nums[i];
            count += nums[i] == majority ? 1 : -1;
        }
        return majority;
    }
};