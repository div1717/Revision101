#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    int numsA[n], numsB[n], numsC[n];
    for (int i = 0; i < n; i++)
        cin >> numsA[i] >> numsB[i] >> numsC[i];

    ll dpA[n + 1], dpB[n + 1], dpC[n + 1];

    dpA[0] = numsA[0], dpB[0] = numsB[0], dpC[0] = numsC[0];
    dpA[1] = numsA[1] + max(numsB[0], numsC[0]);
    dpB[1] = numsB[1] + max(numsA[0], numsC[0]);
    dpC[1] = numsC[1] + max(numsA[0], numsB[0]);

    for (int i = 2; i < n; i++)
    {
        dpA[i] = numsA[i] + max(dpB[i - 1], dpC[i - 1]);
        dpB[i] = numsB[i] + max(dpA[i - 1], dpC[i - 1]);
        dpC[i] = numsC[i] + max(dpA[i - 1], dpB[i - 1]);
    }

    cout << max({dpA[n - 1], dpB[n - 1], dpC[n - 1]}) << endl;
}
