// Using STL next_permuatation
class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(int i=0; i<n; i++)
            str += to_string(i+1);
        
        while(--k){
            next_permutation(str.begin(), str.end());
        }
        
        return str;
    }
};