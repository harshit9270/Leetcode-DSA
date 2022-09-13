// Using Binary Search
// O(n^2logn)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int count = 0, wanted;
        
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                wanted = nums[i] + nums[j];                
                int index = binarySearch(wanted, j + 1, nums);
                
                count += index - j;
            }
        }
        
        return count;
    }
    
    // 3 sides of triangle are valid if a + b > c
    // We can select a & b using 2 for loops
    // To check the third side, we first sort the given array
    // Since c > a && c > b, we definitely know that c will lie beyond b's index
    // So, we search for c such that it is the largest value less than (a + b) and 
    // return its index
    // From the b's index upto this index will be the choices we can have for our side
    
    int binarySearch(int target, int start, vector<int> &nums) {
        int low = start, high = nums.size()-1, mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            
            if (nums[mid] < target) 
                low = mid + 1;
            else 
                high = mid-1;
        }
        
        return high;
    }
};