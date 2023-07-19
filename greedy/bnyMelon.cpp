#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> nums;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }

    map<char, int> mpp;
    for (char start = 'a'; start <= 'z'; start++)
        mpp[start] = 0;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int id = nums[i].first, endTime = nums[i].second, prevEndTime = nums[i - 1].second;
        mpp[id] += (endTime - prevEndTime);
        res = max(res, mpp[id]);
    }

    cout << res << endl;
}
