#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));
    vector<int> preSum(n + 1, 0);

    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    for (int i = 1; i <= n - 1; i++)
        dp[i][i + 1] = nums[i] + nums[i + 1], preSum[i] = preSum[i - 1] + nums[i];

    for (int i = 1; i <= n; i++)
        preSum[i] = nums[i] + preSum[i - 1];

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            int sum = preSum[j] - preSum[i - 1];
            dp[i][j] = INT_MAX;
            for (int p = i; p <= j - 1; p++)
            {
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + sum);
            }
        }
    }

    cout << dp[1][n] << endl;
}