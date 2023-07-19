#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    vector<pair<int, int>> res;
    int minDiff = INT_MAX;

    for (int i = 1; i < nums.size(); i++)
    {
        int diff = nums[i] - nums[i - 1];
        minDiff = min(minDiff, diff);
    }

    for (int i = 1; i < nums.size(); i++)
    {
        int diff = nums[i] - nums[i - 1];
        if (diff == minDiff)
            res.push_back({nums[i - 1], nums[i]});
    }

    for (auto it : res)
        cout << it.first << " " << it.second << endl;
}
