#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool decider(vector<ll> &nums, int k, long long x, int n)
{
    if (nums[k - 1] >= x)
        return true;
    for (int i = 1; i + k < n; i++)
        if (nums[i + k - 1] - nums[i - 1] >= x)
            return true;
    return false;
}

int main()
{
    int n;
    long long target;
    cin >> n;

    vector<ll> nums(n);
    cin >> nums[0];

    for (int i = 1; i < n; i++)
    {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }

    cin >> target;

    int start = 0;
    int end = n + 1;

    while (start + 1 < end)
    {
        int mid = (start + end) / 2;
        if (decider(nums, mid, target, n))
            end = mid;
        else
            start = mid;
    }

    int res = end > n ? -1 : end;
    cout << res << endl;
    return 0;
}