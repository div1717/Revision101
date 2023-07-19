#include <bits/stdc++.h>
using namespace std;

bool compare(int &a, int &b)
{
    return (a > b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);

    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), compare);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += (i + 1) * (nums2[i] - nums1[i]);
    }
}
