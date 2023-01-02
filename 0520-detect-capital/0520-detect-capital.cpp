class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        
        if(word[0] >= 'A' && word[0] <= 'Z'){
            if(word[1] >= 'A' && word[1] <= 'Z'){
                for(int i=1; i<word.size(); i++){
                    if(word[i] > 'Z')
                        return false;
                }
            }
            else{
                for(int i=1; i<word.size(); i++){
                    if(word[i] < 'a')
                        return false;
                }
            }
        }
        else{
            for(char ch : word)
                if(ch >= 'A' && ch <= 'Z')
                    return false;
        }
        
        return true;
    }
};