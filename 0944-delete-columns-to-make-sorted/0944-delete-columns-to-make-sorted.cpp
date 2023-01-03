class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletionCount = 0;
        
        for(int i=0; i<strs[0].size(); i++){
            char lastChar = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] < lastChar){
                    deletionCount ++;
                    break;
                }
                lastChar = strs[j][i];                
            }
        }
        
        return deletionCount;
    }
};