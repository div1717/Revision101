class Solution
{
public:
    int countPalindromes(string s)
    {
        int n = s.size(), res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 3;
            else
                dp[i][i + 1] = 2;
        }
        // for (int len = 3; len <= n; len++)
        // {
        //     for (int i = 0; i < n - len + 1; i++)
        //     {
        //         int j = i + len - 1;
        //         if (s[i] != s[j])
        //             dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        //         else
        //             dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
        //         if (len == 5)
        //             res += dp[i][j];
        //     }
        // }

        return res;
    }
};