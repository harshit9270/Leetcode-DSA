class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,int>> rec;

        for(int i = 0; i < n; i++){
            rec.push_back(make_pair(pos[i], speed[i]));
        }
        stack<float> st;
        sort(rec.begin(), rec.end());
        for(int i = 0; i < n; i++){
            float time = (float)(target-rec[i].first)/(float)rec[i].second;
            while(!st.empty() && st.top() <= time){
                st.pop();
            }
            st.push(time);
        }
        return  st.size();
    }
};