// DP
class Solution {
public:
    long long int arr[38]={0};
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        
        if(arr[n]!=0)
            return arr[n];
        
        return arr[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};