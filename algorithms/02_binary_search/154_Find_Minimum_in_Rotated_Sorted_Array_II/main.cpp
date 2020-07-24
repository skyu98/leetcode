class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if(high == 0 || nums[high] > nums[low]) return nums[0];
        
        while(low < high)
        {
            int mid = low + ((high - low)>> 1);
            if(nums[mid]  > nums[high])
            {
                low = mid + 1;
            }
            else if(nums[mid] == nums[high])
            {
                --high;
            }
            else 
            {
                high = mid;
            }
        }
        return nums[low];
    }
};
