class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] > b[2];
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> rem(1000, 0);
        
        sort(trips.begin(), trips.end(), cmp);
        
        for(int i=0; i<trips.size(); i++){
            for(int j=trips[i][1]; j < trips[i][2]; j++){
                rem[j] += trips[i][0];
                if(rem[j] > capacity)
                    return false;
            }
        }
        
        return true;
    }
};