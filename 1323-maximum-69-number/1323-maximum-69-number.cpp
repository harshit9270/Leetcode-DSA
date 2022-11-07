class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int maxNum = 0;
        bool first6 = true;
        
        for(char ch : s){
            if(ch == '6' && first6){
                maxNum = maxNum*10 + 9;
                first6 = false;
            }
            else
                maxNum = maxNum*10 + (ch - '0');
        }
        
        return maxNum;
    }
};