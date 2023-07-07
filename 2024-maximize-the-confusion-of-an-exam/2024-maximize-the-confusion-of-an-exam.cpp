// Sliding window approach
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxConsAns = 1;
        vector<int> freq(2, 0);
        
        int start = 0, end = 0;
        while(end < answerKey.size()){
            answerKey[end] == 'T' ? freq[1]++ : freq[0]++;
            
            int mini = min(freq[0], freq[1]);
            
            while(mini>k)
            {
                answerKey[start] == 'T' ? freq[1]-- : freq[0]--;
                mini = min(freq[0], freq[1]);
                start ++;
            }
                
            maxConsAns = max(maxConsAns, end-start+1);
            end ++;
        }
        
        return maxConsAns;
    }
};