#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    int dp[n + 1] = {0};

    dp[1] = 0, dp[2] = abs(dp[2] - dp[1]);

    for (int i = 3; i <= n; i++)
        dp[i] = min((abs(nums[i] - nums[i - 1]) + dp[i - 1]), abs(nums[i] - nums[i - 2]) + dp[i - 2]);

    cout << dp[n] << endl;
}
