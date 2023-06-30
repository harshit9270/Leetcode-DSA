class Solution {
public:
    bool isFascinating(int n) {
        vector<int> freq(10, 0);
        vector<int> nums{n, n*2, n*3};
        
        for(auto num : nums)
            while(num){
                freq[num%10] ++;
                num /= 10;
            }
        
        if(freq[0])
            return false;
        
        for(int i=1; i<10; i++)
            if(freq[i] != 1)
                return false;
        
        return true;
    }
};