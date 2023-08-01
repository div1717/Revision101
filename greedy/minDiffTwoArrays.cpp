#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);

    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    int minDiff = INT_MAX, i = 0, j = 0;

    while (i < n && j < n)
    {
        if (nums2[i] >= nums1[j])
        {
            minDiff = min(minDiff, nums2[i] - nums1[j]);
            j++;
        }
        else
            i++;
    }

    cout << minDiff << endl;
    return 0;
}
