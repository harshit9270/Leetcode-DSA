class Solution {
public:
    bool checkIfPangram(string sentence) {
        int counter[123] = {};
        for(int i=0; i<sentence.size(); i++){
            counter[sentence[i]] ++;
        }
        for(int i=97; i<= 122; i++){
            if(counter[i] == 0)
                return false;
        }
        
        return true;
    }
};