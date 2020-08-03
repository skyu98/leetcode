class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while(left < right)
        {
            int mid = left + ((right - left)>>1), cnt = 0;
            for(int i =0;i<nums.size();++i)
            {
                cnt += (nums[i]<=mid);
            }
            if(cnt <= mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};