class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low= 0, high = nums.size() - 1;
        if(high == 0) return 0;

        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            
            if(mid == 0 && nums[mid + 1] < nums[mid]) return mid;
            if(mid == nums.size()-1 && nums[mid - 1] < nums[mid]) return mid;
            if(mid != 0 && mid != nums.size()-1 && nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) return mid;
            
            if(mid == 0 || nums[mid + 1] >= nums[mid])
            {
                low = mid + 1;
            }
            else if(mid == nums.size()-1 || nums[mid - 1] >= nums[mid])
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};