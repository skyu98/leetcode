class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(n<0)
        {
            x = (1/x);
            n = (-1)*n;
        }
        return pow(x, n);
    }
    
    double pow(double x, int n){
        if(n==1) return x;
        if(n==0) return 1;
        
        return x * pow(x,n-1);
    }
};

// Î²µÝ¹é
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x == 1) return 1;
//         if(n<0)
//         {
//             x = (1/x);
//             n = (-1)*n;
//         }
//         return pow(x, x, n);
//     }

//     double pow(double x, double cur, int n){
//         if(n==1) return cur;
//         if(n==0) return 1;
//         cur *= x;
//         return pow(x, cur, n-1);
//     }
// };