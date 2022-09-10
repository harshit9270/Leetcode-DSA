class Solution {
    // Using binary search
private:
   int binSearch(vector<int> n, int lo, int hi, int target)
   {
       while(lo<=hi)
       {
           int mid = lo + (hi-lo)/2;
           if(n[mid]== target )
           {
               return mid;

           }
           else if(n[mid] > target)
           {
               //left
               hi = mid -1;
           }
           else
           {
               lo = mid +1;
           }
       }
       return -1;
   }
       
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums2.size()< nums1.size())
            return intersect(nums2, nums1);

        sort(nums1.begin(), nums1.end()) ;
        sort(nums2.begin(), nums2.end());
        
        for(int i =0; i < nums1.size();i++)
        {
            int curr = nums1[i];
            int idx = binSearch(nums2, 0, nums2.size()-1, curr);
            if(idx !=-1)
            {
                // found in bigger array
                res.push_back(curr);
                // remove from nums2
                nums2.erase(nums2.begin()+idx);

            }
        }
        return res;
    }
};