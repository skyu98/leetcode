// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n<1) return -1;
        int low = 1, high = n;
        
        while(low <= high)
        {
            int mid = low + ((high - low)>>1);
            if(isBadVersion(mid) == false)
            {
                low = mid + 1; 
            }
            else
            {
                if(mid == 1 || isBadVersion(mid - 1) == false)
                {
                    return mid;
                }
                high = mid - 1;
            }
        }
        return -1;
    }
};