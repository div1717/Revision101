#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int currVal = 1;
        string res = "YES";
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == currVal)
            {
                currVal++;
                continue;
            }
            else if (nums[i] < currVal)
            {
                res = "NO";
                break;
            }
            else
            {
                int diff = nums[i] - currVal;
                nums[i] -= diff;
                nums[i + 1] += diff;
            }
            currVal++;
        }
        if (nums[n - 1] != currVal)
            res = "NO";
        cout << res << endl;
    }
}