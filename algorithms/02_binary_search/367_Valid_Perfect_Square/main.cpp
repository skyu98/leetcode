class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2) return true;
        long low = 2, high = num / 2, square = -1;
        while(low <= high)
        {
            long mid = low + ((high - low)>>1);
            square = mid * mid;
            if(square == num) 
            {
                return true;
            }
            else if(square > num)
            {
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return false;
    }
};