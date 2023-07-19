#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[n + 1];

    dp[1] = 0, dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
            dp[i] = 1 + min({dp[i / 2], dp[i / 3], dp[i - 1]});
        else if (dp[i] % 2 != 0 && dp[i] % 3 == 0)
            dp[i] = 1 + min(dp[i / 3], dp[i - 1]);
        else if (dp[i] % 2 == 0 && dp[i] % 3 != 0)
            dp[i] = 1 + min(dp[i / 2], dp[i - 1]);
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[n];
}
