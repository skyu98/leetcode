class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
            if(target >= letters.back()) return letters[0];

            int low = 0, high = letters.size()-1;

            while(low<=high)
            {
                int mid = low + ((high - low)>>1);
                if(letters[mid] > target)
                {
                    if(mid == 0 || letters[mid-1] <= target)
                    {
                        return letters[mid];
                    }
                    high = mid - 1;
                }
                else
                {
                    low =mid + 1;
                }
            }
            return letters[0];
    }
};