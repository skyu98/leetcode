class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long low = 0, high = 0;
        for(int i = 0;i < nums.size();++i)
        {
            high += nums[i];
            if(low <= nums[i])
            {
                low = nums[i];
            }
        }

        while(low< high)
        {
            long long mid =  low + ((high - low)>>1);
            int count = check(nums, mid);
            if(count > m)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

private:
    // 检查在满足划分后最大值为val的情况下，能切成多少段
    int check(const vector<int>& nums, int val){
        int count = 1;
        long long sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
            if(sum > val)
            {
                ++count;
                sum = nums[i];
            }
        }
        return count;
    }
};