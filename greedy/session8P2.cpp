#include <bits/stdc++.h>
using namespace std;

bool compare(int &a, int &b)
{
    return (a > b);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    vector<vector<int>> res(n);
    int start = nums[0], i = 1, iRes = 0;
    res[iRes].push_back(nums[0]);

    while (i < n)
    {
        while (nums[i] - start <= k)
        {
            res[iRes].push_back(nums[i]);
            i++;
        }
        if (nums[i] - start > k)
        {
            iRes++;
            res[iRes].push_back(nums[i]);
            start = nums[i];
            i++;
        }
    }

    for (auto it : res)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
