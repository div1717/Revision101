class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> numsNew;
        numsNew.push_back(1);
        for (auto it : nums)
            numsNew.push_back(it);
        numsNew.push_back(1);

        vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));

        for (int i = 1; i <= n; i++)
            dp[i][i] = numsNew[i - 1] * numsNew[i] * numsNew[i + 1];

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = max(dp[i][j], (numsNew[i - 1] * numsNew[k] * numsNew[j + 1] + dp[i][k - 1] + dp[k + 1][j]));
                }
            }
        }

        return dp[1][n];
    }
};