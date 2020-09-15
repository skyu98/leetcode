# 动态规划

## 121_Best_Time_to_Buy_and_Sell_Stock
此题想先用dp[i][j]表示第i天买入第j天卖出的利润，但这样并没有找出状态转移方程，本质上就是暴力法。
所以应该用dp[i]表示第i天时的最大利润。先只考虑卖出，第i天有两种情况，卖或者不卖，那么：
```dp[i] = max(dp[i - 1], prices[i] - minPrice);```
其中，minPrice是前i天的最低价格；所以，我们需要维护一个minPrice变量来保存最小值。 

时间复杂度：O(n)
空间复杂度：O(n)。因为只用到dp[i - 1]，所以可以优化到O(1)。

