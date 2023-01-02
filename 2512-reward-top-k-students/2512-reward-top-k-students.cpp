class cmp{
public:
    bool operator()(pair<int,int> & p1, pair<int,int> & p2){
        if(p1.first == p2.first)
            return (p1.second > p2.second);
        
        return (p1.first < p2.first);
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> mp;
        
        for(string s : positive_feedback)
            mp[s] = 3;
        for(string s : negative_feedback)
            mp[s] = -1;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        for(int i=0; i<report.size(); i++){
            stringstream ss(report[i]);
            string word;
            int score = 0;
            
            while(ss >> word)
                score += mp[word];
            
            pq.push({score, student_id[i]});
        }
        
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};