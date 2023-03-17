// Using set
class Trie {
    unordered_set<string> s;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return (s.find(word) != s.end());
    }
    
    bool startsWith(string prefix) {
        auto it = s.begin();
        while(it != s.end()){
            if((*it).find(prefix) == 0)
                return true;
            
            it ++;
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */