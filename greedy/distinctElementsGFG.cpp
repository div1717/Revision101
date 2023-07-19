#include <bits/stdc++.h>
using namespace std;

int distinctElements(int n, int k, vector<int> nums)
{
    map<int, int> mpp;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int curr = mpp.find(nums[i]) != mpp.end();
        int next = mpp.find(nums[i] + k) != mpp.end();
        int prev = mpp.find(nums[i] - k) != mpp.end();

        if (curr == 0)
        {
            mpp[curr] = 1;
            continue;
        }
        if (curr && !prev && !next)
        {
            mpp[prev] = 1;
            continue;
        }
        if (curr && prev && !next)
        {
            mpp[next] = 1;
            continue;
        }
        if (curr && next && !prev)
        {
            mpp[prev] = 1;
            continue;
        }
        if (curr && next && prev)
            cnt++;
    }

    return n - cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    distinctElements(n, k, nums);
}
