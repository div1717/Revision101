#include <bits/stdc++.h>
using namespace std;

int minDiffCalc(vector<int> nums1, vector<int> nums2, vector<int> nums3, int n)
{
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

    return minDiff;
}

int minimumValue(int n, vector<int> &A, vector<int> &B, vector<int> &C)
{
    int res = INT_MAX;
    int ab = minDiffCalc(A, B, C, n), ba = minDiffCalc(B, A, C, n);
    int bc = minDiffCalc(B, C, A, n), cb = minDiffCalc(C, B, A, n);
    int ac = minDiffCalc(A, C, B, n), ca = minDiffCalc(C, A, B, n);

    res = min({res, ab, ba, bc, cb, ac, ca});

    return res * 2;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i_A = 0; i_A < N; i_A++)
    {
        cin >> A[i_A];
    }
    vector<int> B(N);
    for (int i_B = 0; i_B < N; i_B++)
    {
        cin >> B[i_B];
    }
    vector<int> C(N);
    for (int i_C = 0; i_C < N; i_C++)
    {
        cin >> C[i_C];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int out_;
    out_ = minimumValue(N, A, B, C);
    cout << out_;
}