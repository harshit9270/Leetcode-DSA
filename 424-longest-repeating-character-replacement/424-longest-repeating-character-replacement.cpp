class Solution {
public:
    int characterReplacement(string s, int k) {
      
        
        /* Store the occurence of each charater in our window */
        vector<int> frequency(26,0);    
        
        
        int end = 0;     // Start pointer of our window
        int start = 0;   // End pointer of our window
        
        
        /* Store max frequency overall */
        int max_freq = 0; 
        
        int ans = 0;
        
        while(end < s.length())
        {
            frequency[s[end] - 'A']++;  // updating frequency of character
            
            max_freq = max(max_freq, frequency[s[end] - 'A']);
            
            /* if our window size - max_freq > k 
            *    meaning -> we change more character then needed, we will shrink our window.
            *     
            *    end - start + 1 = current window size.
            */
            
			/* The while loop is removed as this will run only once */
            if(end - start + 1 - max_freq > k)
            {
                ans = max(ans, end-start);
                frequency[s[start] - 'A']--;
                start++; // reducing window.
            }
            end++;
        }
        
        ans = max(ans, end-start);
        return ans;
        
        
    }
};