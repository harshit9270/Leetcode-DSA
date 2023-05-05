class Solution {
public:
    int maxVowels(string s, int k) {
        int curCount = 0, maxCount = 0;
        for(int i=0; i<k; i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                curCount++;
            }
        }
        
        maxCount = max(maxCount, curCount);
        
        for(int i=k; i<s.size(); i++){
            if(s[i-k]=='a' or s[i-k]=='e' or s[i-k]=='i' or s[i-k]=='o' or s[i-k]=='u')
                curCount--;
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
                curCount++;
            
            maxCount = max(maxCount, curCount);
        }
        
        return maxCount;
    }
};