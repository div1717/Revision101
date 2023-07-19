#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int negatives = 0, zeros = 0, positives = 0, prodAll = 1, largestNeg = INT_MIN, smallestPos = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            zeros++;
        else if (nums[i] < 0)
            negatives++, prodAll *= abs(nums[i]), largestNeg = max(nums[i], largestNeg);
        else
            positives++, prodAll *= abs(nums[i]), smallestPos = min(smallestPos, nums[i]);
    }

    if (zeros == 0 && negatives % 2 == 1)
        cout << -1 * prodAll << endl;
    else if (zeros == 0 && negatives != 0 && negatives % 2 == 0)
        cout << prodAll / largestNeg << endl;
    else if (zeros != 0 && negatives == 0)
        cout << 0 << endl;
    else
        cout << smallestPos << endl;
}