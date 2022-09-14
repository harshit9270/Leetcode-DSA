// Prefix Sum | Binary Search

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = -1;
        vector<long long> presum(chalk.size(),0);
        
        presum[0]=chalk[0];
        for(int i=1;i<chalk.size();i++)
            presum[i]=chalk[i]+presum[i-1];
        
        k = k%presum[chalk.size()-1];
        
        int start = 0, end = chalk.size()-1;
        
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(presum[mid]==k)
                return mid+1;
            else if(presum[mid]<k)
                start=mid+1;
            else
                end=mid-1;
        }
        
        return start;
    }
};