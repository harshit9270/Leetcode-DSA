// Optimized O(log n)
class Solution {
public:    
    int search(vector<int>& arr, int target, bool findFirstIndex )
    {
        int high = arr.size() -1;
        int low = 0;

        int ans  = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else if(arr[mid] < target)
            {
                low = mid + 1;
            }
            else{
                ans = mid;


                if(findFirstIndex){
                high = mid - 1;

                }
                else{
                    low = mid + 1;
                }
            }
        }

      return ans;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int fi =  search(arr, target, true);
        int li =  search(arr, target, false);


        ans[0] = fi;
        ans[1] = li;
        return ans;
    }
};