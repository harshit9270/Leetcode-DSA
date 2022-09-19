// Using STL next_permuatation
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            v[i] = i+1;
        }
        
        while(--k){
            next_permutation(v.begin(), v.end());
        }
        
        string res = "";
        for(int i=0; i<n; i++)
            res += to_string(v[i]);
        
        return res;
    }
};