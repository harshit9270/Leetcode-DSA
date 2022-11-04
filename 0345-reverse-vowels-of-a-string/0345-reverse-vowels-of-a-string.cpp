// Using stack
class Solution {
    bool isVowel(char ch){
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if(vowels.find(ch) != vowels.end())
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        stack<char> vowelsInS;
        vector<int> indices;
        
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                vowelsInS.push(s[i]);
                indices.push_back(i);
            }
        }
        
        int i = 0;
        while(! vowelsInS.empty()){
            auto top = vowelsInS.top();
            vowelsInS.pop();
            
            s[indices[i]] = top;
            i++;
        }
        
        return s;
    }
};