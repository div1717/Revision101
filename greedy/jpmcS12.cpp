#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve(string &s)
{
    int cnt = 0, n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == '1' && nums[i + 1] == '0')
            cnt++;
    }

    return s[n - 1] == '1' ? cnt * 2 + 1 : cnt * 2;
}

int main()
{
    string s;
    cin >> s;

    int res = solve(s);
    cout << res << endl;
}

// leetcode 1529

/**
 * class Solution {
public:
    int minFlips(string s) {
        int cnt = 0, n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
            cnt++;
    }

    return s[n - 1] == '1' ? cnt * 2 + 1 : cnt * 2;
    }
};
*/
