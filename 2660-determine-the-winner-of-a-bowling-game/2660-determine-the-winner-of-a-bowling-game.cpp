class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0, score2 = 0;
        int prev1 = 0, prev2 = 0;
        
        for(int i=0; i<player1.size(); i++){
            if(prev1 == 10 || prev2 == 10)
                score1 += 2*player1[i];
            else
                score1 += player1[i];
            
            prev2 = prev1;
            prev1 = player1[i];
        }
        
        prev1 = 0; prev2 = 0;
        
        for(int i=0; i<player2.size(); i++){
            if(prev1 == 10 || prev2 == 10)
                score2 += 2*player2[i];
            else
                score2 += player2[i];
            
            prev2 = prev1;
            prev1 = player2[i];
        }
        
        if(score1 == score2)
            return 0;
        
        return (score1 < score2) ? 2 : 1;
    }
};