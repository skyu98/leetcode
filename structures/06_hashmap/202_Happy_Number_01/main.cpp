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
        unordered_set<int> set;
        while( n!= 1 )
        {
            set.insert(n);
            n = _next(n);
            if(set.count(n) == 1) return false;
        }
        return true;
    }
};