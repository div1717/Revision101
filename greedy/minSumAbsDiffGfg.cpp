long long findMinSum(vector<int> &a, vector<int> &b, int n)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < n; i++)
        res += abs(a[i] - b[i]);

    return res;
}