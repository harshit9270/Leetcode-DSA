class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        
        int size = 1;
        while(size <= n){
            n -= size;
            count++;
            
            size++;
        }
        
        return count;
    }
};