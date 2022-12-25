class Solution {
public:
    int binary(vector<int> &n, int target){
        int s = 0, e = n.size() - 1, m;

        while (s <= e){
            m = s + (e-s)/2;
            if (n[m] > target)
                e = m - 1;  //it'll point to the required element eventually in case target
                            // is not present in nums.
            
            else if (n[m] < target)
                s = m + 1;   //s will pass the required element if(target < n[m]);

            else             // if (target == n[m])
                return m + 1;
        }
        
        return e+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries){
        int a = nums.size(), b = queries.size();
        sort(nums.begin(), nums.end());

        //prefix sum 
        for (int i = 1; i < a; i++)
            nums[i] += nums[i-1];

       //binary search 
        for (int i = 0; i < b; i++)
            queries[i] = binary(nums, queries[i]);
        
        return queries;
    }
};