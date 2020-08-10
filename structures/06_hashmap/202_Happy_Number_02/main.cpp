class Solution {
public:
    int _next(int n)
    {
        long sum = 0;
        while(n > 0)
        {
            int unit = n % 10;
            sum += unit * unit;
            n /= 10;
        }
        return sum; 
    }   

    bool isHappy(int n) {
        int fast = n, slow = n;
        while(fast != 1)
        {
            fast = _next(_next(fast));
            slow = _next(slow);
            if(fast == slow) break;
        }
        return fast == 1;
    }
};