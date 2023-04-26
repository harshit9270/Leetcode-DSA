class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        
        while(num > 9){
            int temp = num;
            while(temp){
                sum += (temp%10);
                temp /= 10;
            }
            num = sum;
            sum = 0;
        }
        
        return num;
    }
};