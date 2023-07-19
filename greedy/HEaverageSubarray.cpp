#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int cnt = 0, prev = 1, res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1 && prev == 1)
                cnt++;
            else if(nums[i] == 1 && prev == 0)
                cnt = 1;
            if (cnt == k)
                res++, cnt =0;
            else prev = nums[i];
        }
        cout<<res<<endl;
    }

}