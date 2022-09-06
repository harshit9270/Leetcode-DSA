class Solution {
public:
    // Using binary search
    int findKthPositive(vector<int> &arr, int k)
    {
        int start = 0, end = arr.size()-1, ans;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            int missed = arr[mid] - mid - 1;
            
            if (missed >= k)
            {
                ans = arr[mid] - (missed - k) - 1;
                end = mid - 1;
            }
            
            if (missed < k)
            {
                start = mid + 1;
                ans = arr[mid] + k - missed;
            }
        }
        
        return ans;
    }
};