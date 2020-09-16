class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        if(len1 == 0||len2 ==0) return 0;
        vector<vector<int>> dp (len1+1, vector<int>(len2+1, 0));

        for(int i = 1;i<len1+1;++i)
        {
            for(int j = 1;j<len2+1;++j)
            {
                
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[len1][len2];

    }
};