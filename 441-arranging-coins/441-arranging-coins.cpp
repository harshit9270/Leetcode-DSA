class Solution {
public:
    // Using binary search
    int arrangeCoins(int n) {
        int start = 1, end = n;
        
        while(start <= end){
            long mid = start + (end-start)/2;
            long total = (mid*(mid+1))/2;
            
            if(total == n)
                return mid;
            else if(total < n)
                start = mid+1;
            else
                end = mid-1;
        }
        
        return end;
    }
};