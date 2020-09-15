class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;

        vector<int> dp(len, 0);
        int minPrice = prices[0];

        for(int i = 1;i<len;++i)
        {
            minPrice = min(prices[i], minPrice);
            dp[i] = max(dp[i - 1], prices[i] - minPrice); 
            cout << dp[i] << endl;
        }        

        return dp[len - 1];
    }
};