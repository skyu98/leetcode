class Solution {
public:
    int guessNumber(int n) {
        int low = 0, high = n;
        while(low<=high)
        {
            int mid = low + ((high - low)>>1);
            int res = guess(mid);
            if(res == 0) return mid;
            if(res == -1) 
            {
                high = mid - 1;
            }
            else
            {
                low = mid +1;
            }
        }
        return -1;
    }
};