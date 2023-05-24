//  SLIDING WINDOW 
//  TIME COMPLEXITY O(2n)
//  SPACE COMPLEXITY O(m)   
        
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int store[256]={0}; 
        int l=0;    //left pointer
        int r=0;    //right pointer
        int ans=0;  
        
        while(r<s.length()){
            store[s[r]]++;      
            
            while(store[s[r]]>1){
                //if the occurence become more than 1 means the char is repeated
                store[s[l]]--; 
                l++;         
            }
            
            ans = max(ans,r-l+1);    
            r++;      
        }
        
        return ans;
    }
};