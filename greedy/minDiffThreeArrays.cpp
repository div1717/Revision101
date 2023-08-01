#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);
    vector<int> nums3(n);

    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    for (int i = 0; i < n; i++)
        cin >> nums3[i];

    int minDiff = INT_MAX, i = 0, j = 0, k = 0;

    while (i < n && j < n && k < n)
    {
        if (nums3[k] >= nums2[j])
        {
            if (nums2[j] >= nums1[i])
            {
                minDiff = min(minDiff, ((nums3[k] - nums2[j]) + (nums2[j] - nums1[i])));
                i++;
            }
            else
                j++;
        }
        else
            k++;
    }

    cout << minDiff << endl;
    return 0;
}
