#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int q;
    cin >> q;
    vector<pair<int, int>> query(q);
    for (int i = 0; i < n; i++)
    {
        cin >> query[i].first;
        cin >> query[i].second;
    }

    int sum = 0;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        mpp[i] = sum;
    }

    for (int k = 0; k < q; k++)
    {
        int i = query[k].first, j = query[k].second;
        cout << (mpp[j] - mpp[i]) + nums[i] << endl;
    }
    return 0;
}