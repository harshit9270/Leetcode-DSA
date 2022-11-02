// Graph Theory BFS
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s{bank.begin(),bank.end()};
        if(! s.count(end)) 
            return -1;
        
        queue<string> q;
        q.push(start);
        
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size --){
                string curr = q.front();
                q.pop();
                
                if(curr == end) 
                    return steps;
                
                s.erase(curr);
                
                for(int i=0; i<8; i++){
                    string temp = curr;
                    temp[i]='A';
                    if(s.count(temp)) 
                        q.push(temp);
                    temp[i]='C';
                    if(s.count(temp)) 
                        q.push(temp);
                    temp[i]='G';
                    if(s.count(temp)) 
                        q.push(temp);
                    temp[i]='T';
                    if(s.count(temp)) 
                        q.push(temp);
                }
            }
            steps++;
        }
        
        return -1;
    }
};