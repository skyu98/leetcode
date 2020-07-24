class Solution {
public:
    int _find(vector<int>& nums, int low, int high){
        if(low == high) return low;
        int mid = low + ((high - low) >> 1);
        // low < high 就保证了nums[mid+1]没有越界
        if(nums[mid + 1] > nums[mid])
        {
            return _find(nums, mid + 1, high);
        }
        else 
        {
            // nums[mid + 1] < nums[mid]时，mid有可能是峰值；
            // 所以区间要把mid包括进去
            return _find(nums, low, mid);
        }
        // low==high 时退出，两者都指向峰值元素
    }

    int findPeakElement(vector<int>& nums) {
        int low= 0, high = nums.size() - 1;
        if(high == 0) return 0;
        return _find(nums, low, high);
    }
};