// We can move our army from 1 to -1. So, if we know the index of 1's and -1's , we can easily know the number of zeroes between them by simply taking the absolute difference of their indexes.

class Solution {
public:
    int captureForts(vector<int>& forts) {
        stack<pair<int,int>> st;
        int ans = 0 , n = forts.size();
        for(int i=0 ; i<n ; i++){
            if(forts[i] != 0){
                if(st.empty())
                    st.push({forts[i],i});
                else{
                    if((forts[i] == 1 && st.top().first == -1) || (forts[i] == -1 && st.top().first == 1))
                        ans = max(ans,i-st.top().second-1);
                    st.push({forts[i],i});
                }
            }
        }
        return ans;
    }
};
