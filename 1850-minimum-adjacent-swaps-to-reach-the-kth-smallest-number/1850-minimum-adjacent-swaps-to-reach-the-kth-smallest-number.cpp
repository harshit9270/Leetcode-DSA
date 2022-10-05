class Solution {
public:
    void nextPermutation(string & nums) {
	    // Narayana Panditha's Algorithm
        int len=nums.size(), k=0, l=0;
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
    
    int getMinSwaps(string num, int k) {
        string original = num;
        
        while(k--)
            nextPermutation(num);
        
        // counting steps required by matching target string with original one
        int ans=0;
        for(int i=0; i<num.size(); i++){
            if(original[i] != num[i]){
              int j=i+1 ;// j will be moving in original string

              while(original[j] != num[i])
              {
                  j++;
              }

              while(j>i)
              {
                  swap(original[j] , original[j-1]);
                  j--;
                  ans++;
              }
            }
        }
        
        return ans;
    }
};