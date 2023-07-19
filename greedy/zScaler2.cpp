#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<pair<int, int>> numsIdx;

    for (int i = 0; i < n; i++)
        numsIdx.push_back({nums[i], i});

    sort(numsIdx.begin(), numsIdx.end());
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int index = numsIdx[i].second;
        if (nums[index] == 0)
            continue;

        res += nums[index];
        nums[index] = 0;
        if (0 < index)
            nums[index - 1] = 0;
        if (index < n - 1)
            nums[index + 1] = 0;
    }

    cout << res << endl;
}
