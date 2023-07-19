#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n + 1);
    for (long long i = 1; i <= n; i++)
        cin >> nums[i];

    long long dp[n + 1] = {0};

    dp[1] = 0, dp[2] = abs(nums[2] - nums[1]);

    for (long long i = 3; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (long long j = 1; j <= k; j++)
            if ((i - j) >= 1)
                dp[i] = min(dp[i], abs(nums[i] - nums[i - j]) + dp[i - j]);
    }

    cout << dp[n] << endl;
}
