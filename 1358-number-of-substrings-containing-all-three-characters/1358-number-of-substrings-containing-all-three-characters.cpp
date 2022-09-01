class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, end = s.size() - 1;
        int count = 0;
        vector<int> freq(3);
        
        while(right < s.length()){
            freq[s[right] - 'a']++; //add next element to window
                        
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) // while(window is good)
            {
                count += 1 + (end - right);
                
				// removing first element
                // [means shrinking window from front to form new window]
                
                freq[s[left] - 'a'] -= 1; 
                left++;
            }
            
            right ++;
        }
        
        return count;
    }
};