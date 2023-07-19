/**
 * Given a number N. The task is to reduce the given number N to 1 in the minimum
 * number of steps. You can perform any one of the below operations in each step.
    Operation 1: If the number is even then you can divide the number by 2.
    Operation 2: If the number is odd then you are allowed to perform either (n+1) or (n-1).
*/

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
        if (i % 2 == 0)
            dp[i] = 1 + dp[i / 2];
        else
            dp[i] = 2 + min(dp[(i + 1) / 2], dp[(i - 1) / 2]);
    }

    cout << dp[n] << endl;
}