class Solution {
public:
    int _bsearch(vector<int>& nums, int low, int high, int& target){
        if(low>high) return -1;
        int mid = low + ((high - low) >> 1);
        if(nums[mid] == target) return mid;
        if(nums[mid] < target)
        {   
            return _bsearch(nums, mid + 1, high, target);
        }
        else
        {
            return _bsearch(nums, low, mid - 1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return _bsearch(nums, low, high, target);
    }
};