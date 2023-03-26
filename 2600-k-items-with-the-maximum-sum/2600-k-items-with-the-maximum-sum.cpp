class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        
        if(k > 0){
            if(numOnes < k){
                k -= numOnes;
                sum += numOnes;
            }
            else{
                sum += k;
                k = 0;
            }
        }
        if(k > 0){
            if(numZeros < k){
                k -= numZeros;
            }
            else{
                k = 0;
            }
        }
        if(k > 0){
            if(numNegOnes < k){
                k -= numNegOnes;
                sum -= k;
            }
            else{
                sum -= k;
                k = 0;
            }
        }
        
        return sum;
    }
};