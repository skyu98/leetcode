class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len % 2 == 1)
        {
            return _theKthNum(nums1, nums2, (len + 1)>> 1);
        }
        else
        {
            return (_theKthNum(nums1, nums2, len >> 1) + _theKthNum(nums1, nums2, (len + 2)>> 1) ) * 0.5;
        }
    }

private:
    double  _theKthNum(const vector<int>& nums1, const vector<int>& nums2, int k){
        int len1 = nums1.size(), len2 = nums2.size();
        
        int idx1 = 0, idx2 = 0;// 每次开始时数组的左边界

        while(true)
        {
            // 如果有一方已经全部排除或者为空，则返回另一数组第K元素
            if(idx1 >= len1) return nums2[idx2 + k - 1];
            if(idx2 >= len2) return nums1[idx1 + k - 1];
            // 如果k=1，那么直接返回数组左边界两个值中的较小值
            if(k == 1) return min(nums1[idx1], nums2[idx2]);

            // 避免出现剩余数组长度不足k/2，从而越界的情况
            int pivot1 = min(idx1 + k/2, len1) - 1;
            int pivot2 = min(idx2 + k/2, len2) - 1;

           /*取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
            * 这样 pivot 本身最大也只能是第 k-1 小的元素
            * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组;nums2同理
            * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
            */

            if(nums1[pivot1] <= nums2[pivot2])
            {
                k -= (pivot1 - idx1 + 1);
                idx1 = pivot1 + 1;
            }
            else
            {
                k -= (pivot2 - idx2 + 1);
                idx2 = pivot2 + 1;
            }
        }
    }
};