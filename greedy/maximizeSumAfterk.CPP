#include <bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int nums[], int n, int k)
{
    sort(nums, nums + n);
    long long int totalSum = 0, negatives = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            negatives++;
        totalSum += abs(nums[i]);
    }
    if (negatives == k)
        return totalSum;
    else if (negatives < k)
    {
        int temp = k - negatives;
        if (temp % 2 == 1)
        {
            if (negatives != n)
                return totalSum - (2 * nums[negatives]);
            else
                return totalSum - (2 * abs(nums[n - 1]));
        }
        else
            return totalSum;
    }
    else
    {
        for (int i = k; i < n; i++)
            if (nums[i] < 0)
                totalSum += (2 * nums[i]);
        return totalSum;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    long long int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maximizeSum(nums, n, k) << endl;
}