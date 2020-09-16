class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        vector<int> dp(len, 0);

        dp[0] = nums[0];
        int maxSum = nums[0];

        for(int i = 1;i<len;++i)
        {
            if(nums[i] + dp[i-1] >= nums[i]) dp[i] = dp[i - 1] + nums[i];
            else dp[i] = nums[i];
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};