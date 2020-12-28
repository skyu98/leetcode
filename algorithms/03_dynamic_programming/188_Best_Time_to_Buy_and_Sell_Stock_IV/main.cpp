class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.empty()) return 0;

        int size = prices.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(k + 1, vector<int>(2, 0)));  // i：天数；k：当前交易次数；0/1：是否持有股票

        k = min(size >> 1, k); // 最多n/2次交易

        // base case
        for(int j = 0;j < k + 1;++j)  // 第0天
        {
            dp[0][j][0] = 0;  // 手上无股票，利润为0
            dp[0][j][1] = -prices[0];    //  手上有股票，利润为-price[0]
        }

        for(int i = 1;i < size; ++i)
        {
            for(int j = 0;j < k + 1;++j)
            {
                if(j == 0)
                    dp[i][j][0] = dp[i-1][j][0];  // 啥都没干
                else
                    // 什么都不干，或者是将前一天手中的的卖出
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]);
                // 什么都不干，或者是在今天买进
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i]);
            }
        }

        int maxRes = 0;
        for(int i = 0;i < k+1; ++i)
        {
            // 在最后一天，所有手里没有股票的情况下，最大的利润
            maxRes = max(maxRes, dp[size-1][i][0]); 
        }

        return maxRes;
    }
};