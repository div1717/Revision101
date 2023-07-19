#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> in(n), out(n);

    for (int i = 0; i < n; i++)
        cin >> in[i];

    for (int i = 0; i < n; i++)
        cin >> out[i];

    vector<pair<int, int>> pii(n);
    vector<pair<int, int>> res;

    for (int i = 0; i < n; i++)
        pii[i].push_back({int[i], out[i]});

    sort(pii.begin(), pii.end());

    int prevEnd = pii[0].second;
    int currStart;

    for (int i = 1; i < n; i++)
    {
        currStart = pii[i].first;
        if (prevEnd < currStart)
            res.push_back({prevEnd, currStart});
        prevEnd = pii[i].second;
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
}
