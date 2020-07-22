class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0) return x;
        int low, high;

        low  = 1;
        high = x;

        while(low <= high )
        {
            int mid = low + ((high - low)>>1);
            if(mid <= x/mid)
            {
                if(mid+1 > x/(mid+1)) return mid;
                low = mid;
            }
            else high = mid;
        }
        return -1;
  }
};