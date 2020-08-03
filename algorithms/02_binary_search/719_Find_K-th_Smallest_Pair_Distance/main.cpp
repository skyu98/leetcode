class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[nums.size()-1] - nums[0];

        while(low < high)
        {
            int mid = low + ((high - low) >> 1);
            int left = 0, right = 0, count = 0;
            for(right=0;right<nums.size();++right)
            {
                // 计算距离比mid小的数对有多少个
                while(left < nums.size() && nums[right] - nums[left] > mid) ++left;
                // 找到第一个小于等于元素之后，两者之间的就是满足要求的
                count += right - left;
            }

            if(count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;// 这样保证了找到的mid一定是存在的数对距离，不断往左逼近。
            }
        }
        return low;
    }
};