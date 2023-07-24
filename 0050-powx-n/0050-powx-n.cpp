// Using recursion
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        
        // if n is even then, x^n = x^(n/2) * x^(n/2);
        // if n is odd then, x^n = x*(x^(n/2) * x^(n/2));
        // coz n/2 returns quotient only that excludes the extra 1 power
        
        if(n%2==0){
            return myPow(x*x,n/2);
        }
        else{
            return x*myPow(x*x,n/2);
        }
        
    }
};