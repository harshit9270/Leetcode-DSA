class Solution {
typedef long long ll;
public:
    int minimumPartition(const string&s, int k) {
        ll ans=0, num=0;
        
        for(ll i=0; i<s.size(); ++i){
            if(s[i]-'0' > k)
                return -1;
            
            num = (num * 10) + (s[i] - '0');
            
            if(num > k) // number from prev pos to i-1 was ok, now must start a new num from i
                ++ans, num = s[i] - '0'; 
        }
        
        // +1 for the remainder in 'n' that was not taken care of due to the end of the loop
        return 1 + ans; 
    }
};