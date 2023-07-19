#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string S)
{
    // dp[i][j] represents if substring from index i to j is a palindrome or not
    int n = S.size(), res = 1, maxi = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // dp state for all substrings of length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // dp state for all substrings of length 2
    for (int i = 0; i < n - 1; i++)
    {
        if (S[i] == S[i + 1])
        {
            dp[i][i + 1] = 1;
            if (2 > res)
            {
                res = 2;
                maxi = i;
            }
        }
    }

    // dp state for all substrings of lenght len
    // for substring(i - j) if substring(i+1 - j-1)
    // is palindrome and S[i] == S[j] then
    // substring(i - j) is a plaindrome.
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            if ((dp[i + 1][i + len - 2] == 1) && S[i] == S[i + len - 1])
            {
                dp[i][i + len - 1] = 1;
                if (len > res)
                {
                    res = len;
                    maxi = i;
                }
            }
        }
    }

    string ansStr = S.substr(maxi, res);
    return ansStr;
}

int main()
{
    string S;
    cin >> S;
    cout << longestPalindrome(S);
}