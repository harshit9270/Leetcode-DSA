class Solution {
public:
    vector<int> findErrorNums(vector<int>&nums) {
        vector<int> freq(nums.size()+1, 0);
        vector<int> vec(2);
        
        for(int i : nums)
            freq[i]++;
        
        for(int i=0; i<freq.size(); ++i){
            if(freq[i]==2)
                vec[0]=i;
            if(freq[i]==0)
                vec[1]=i;
        }
        
        return vec;
    }
};