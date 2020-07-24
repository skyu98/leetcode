class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if(high == 0) return nums[0];

        while(low < high)
        {
            int mid = low + ((high - low)>> 1);
            if(nums[mid]  > nums[high])
            {
                low = mid + 1;
            }
            else 
            {
                high = mid;
            }
        }
        return nums[low];
    }
};