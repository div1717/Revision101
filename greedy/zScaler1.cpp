#include <bits/stdc++.h>
using namespace std;

int help(int n)
{
    // int baseValue, packets = 0;
    // while (n)
    // {
    //     baseValue = log2(n);
    //     n -= pow(2, baseValue);
    //     packets++;
    // }
    // return packets;

    //---- or this ----

    // return __builtin_popcount(n);

    //---- or this ----

    int packets = 0;
    bitset<> bnry(n);
    for (int i = 0; i < 64; i++)
        if (bnry[i] == 1)
            packets++;
    retunr packets;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> uploaded(m, vector<int>(2));

    for (int i = 0; i < m; i++)
        cin >> uploaded[i][0] >> uploaded[i][1];

    sort(uploaded.begin(), uploaded.end());

    vector<int> leftRanges;
    int initial = 1;
    for (int i = 0; i < m; i++)
    {
        int start = uploaded[i][0], end = uploaded[i][1];
        int range = start - initial;
        if (range)
            leftRanges.push_back(range);
        initial = end + 1;
    }

    int res = 0;
    for (auto it : leftRanges)
        res += help(it);

    cout << res << endl;
}
