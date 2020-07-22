class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 1) return -1;
        if(size == 1) return nums[0] == target ? 0: -1;
        int left = 0, right = nums.size()-1;
       
        while(left <= right)
        {
            int mid = left + ((right - left)>>1);
            if(target == nums[mid]) return mid;
            if(nums[mid] >= nums[0])
            {
                if(target < nums[mid] && target >= nums[0])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target > nums[mid] &&　target <= nums[size-1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};