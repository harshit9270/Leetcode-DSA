class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) 
            return -1;
        
        // satisfy condition 2 first, given 1 dollar to each children
        money -= children;

        int ans = 0;
        while(money >= 7 && children > 0) {
            money -= 7;
            ans++;
            children--;
        }
        
        if(ans) {
            if(children == 0 && money > 0) ans -= 1;
            if(children == 1 && money == 3) ans -= 1;
        }
         
        return ans;
    }
};