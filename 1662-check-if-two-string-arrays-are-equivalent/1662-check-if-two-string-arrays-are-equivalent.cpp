class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string wordA = "", wordB = "";
        
        for(int i=0; i<word1.size(); i++){
            wordA += word1[i];
        }
        
        for(int i=0; i<word2.size(); i++){
            wordB += word2[i];
        }
        
        if(wordA == wordB)
            return true;
        
        return false;
        
    }
};