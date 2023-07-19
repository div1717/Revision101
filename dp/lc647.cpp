class Solution
{
public:
    int dp[1001][1001];
    int countSubstrings(string s)
    {
        // dp[i][j] represents if substring from index i to j is a palindrome or not
        int n = s.size(), res = 0;
        // dp state for all substrings of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1, res++;

        // dp state for all substrings of length 2
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 1, res++;

        // dp state for all substrings of lenght len
        // for substring(i - j) if substring(i+1 - j-1)
        // is palindrome and s[i] == s[j] then
        // substring(i - j) is a plaindrome.
        for (int len = 3; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++)
                if ((dp[i + 1][i + len - 2] == 1) && s[i] == s[i + len - 1])
                    dp[i][i + len - 1] = 1, res++;

        return res;
    }
};