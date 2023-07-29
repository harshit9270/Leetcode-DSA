class Solution {
public:
    int characterReplacement(string s, int k) {
     int head = 0;
     int tail = 0;
     int ans = 0;
     int cnt[26]={};
     int maxFreq = INT_MIN;
     for(head = 0;head<s.length();head++){
         cnt[s[head] - 'A']++; // increase frequency of current element
         maxFreq = max(maxFreq,cnt[s[head] - 'A']); 
         // logic is if number of disimilar elements in window are greater than k then that window cannot be our answer as we cannot convert all element of window equal
         // how to number of calculate dissimilar element
         // totalSizeOfWindow(head-tail+1) - maxFreq(element that has max Frequency in a window)
         // optimal solution is to convert all elements equal to maxFrequency element of window
         while(head - tail + 1 - maxFreq > k){
             cnt[s[tail] - 'A']--;
             tail++;
         }
         ans = max(ans,head - tail + 1);
         
     }
     return ans;
    }
};