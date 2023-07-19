/**
 * Given an integer element ‘N’, the task is to find the minimum number of operations
 * that need to be performed to make ‘N’ equal to 1.
 *The allowed operations to be performed are:
    Decrement N by 1.
    Increment N by 1.
    If N is a multiple of 3, you can divide N by 3.
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
        if (i % 3 == 0)
            dp[i] = 1 + dp[i / 3];
        else
            dp[i] = 2 + ((i + 1) % 3 == 0 ? (dp[(i + 1) / 3]) : (dp[(i - 1) / 3]));
    }

    cout << dp[n];
}