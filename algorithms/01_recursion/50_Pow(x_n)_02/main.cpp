class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        long long N = n;
        if(n<0)
        {
            x = (1/x);
            N = -N;
        }
        return pow(x, N);
    }
    
    double pow(double x, long long n){
        if(n==0) return 1;
        double half = pow(x, n/2);
        if(n%2==0) 
        {
            return half * half;
        }
        else
        {
             return half * half*x;
        }
    }
};
