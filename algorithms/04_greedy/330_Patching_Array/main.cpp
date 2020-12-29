class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long long upperBound = 0; // 现在能够覆盖的范围上界
        int idx = 0, size = nums.size();

        while(upperBound < n)
        {
			/* 1.都超出了界限还是没能覆盖到n，那肯定要添加新的数字
			 * 2.如果下一个数字小于等于 upperBound + 1， 那说明不用添加新的数字，扩大 upperBound
			 * 3.如果下一个数字比 upperBound + 1 还大，那么需要添加新的数字；否则覆盖不到
			 [upperBound + 1, num[idx])
			 */
            if(idx < size && (upperBound + 1 >= nums[idx]))
            {
                upperBound += nums[idx++];
            }
            else
            {
                ++res;
				// 加入的数字不能大于 upperBound + 1, 为了使区间最大程度扩大
				// 我们使用贪心算法， 直接添加 upperBound + 1
                upperBound += (upperBound + 1);
            }
        }

        return res;
    }
};
