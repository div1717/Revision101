#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

long long int countPS(string s)
{
    // Your code here
    int n = s.size();

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 3;
        else
            dp[i][i + 1] = 2;
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] != s[j])
                dp[i][j] = ((dp[i][j - 1] % mod + dp[i + 1][j] % mod) % mod - dp[i + 1][j - 1] % mod + mod) % mod;
            else
                dp[i][j] = (dp[i][j - 1] % mod + dp[i + 1][j] % mod + 1) % mod;
        }
    }

    return dp[0][n - 1] % mod;
}

int main()
{
    string s;
    cin >> s;
    cout << countPS(s) << endl;
}