class Solution {
public:
    int characterReplacement(string s, int k) {
      
        
        /* Store the occurence of each charater in our window */
        vector<int> frequency(26,0);    
        
        
        int end = 0;     // End pointer of our window
        int start = 0;   // Start pointer of our window
        
        
        /* Store max frequency within window */
        int max_freq_within_window = 0; 
        
        int ans = 0;  // our final answer to return
        
        while(end < s.length())
        {
            frequency[s[end] - 'A']++;  // updating frequency of character
            
            max_freq_within_window = max(max_freq_within_window, frequency[s[end] - 'A']);
            
            /* if our window size - max_freq > k 
            *    meaning -> we change more character then needed, we will shrink our window.
            *    See example below.
            *     
            *    end - start + 1 = current window size.
            */
            
            while(end - start + 1 - max_freq_within_window > k)
            {
                ans = max(ans, end-start);
                frequency[s[start] - 'A']--;
                start++; // reducing window.
                
                /* since we removed one element from window, we should update our 
                   max_freq_within_window variable too.
                */
                max_freq_within_window = *max_element(frequency.begin(),frequency.end());
            }
            end++;
        }
        ans = max(ans, end-start);
        return ans;
        
        
    }
};