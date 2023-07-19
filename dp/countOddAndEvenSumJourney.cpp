#include <bits/stdc++.h>
using namespace std;

int main()
{
    // inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> evenDp(n + 1, 0), oddDp(n + 1, 0);

    // base cases
    if (nums[0] % 2 == 0)
        evenDp[0] = 1;
    else
        oddDp[0] = 1;

    if ((nums[1] + nums[2]) % 2 == 0)
        evenDp[1] = 1;
    else
        oddDp[1] = 1;

    for (int i = 2; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            evenDp[i] = evenDp[i - 1] + evenDp[i - 2];
            oddDp[i] = oddDp[i - 1] + oddDp[i - 2];
        }
        else
        {
            evenDp[i] = oddDp[i - 1] + oddDp[i - 2];
            oddDp[i] = evenDp[i - 1] + evenDp[i - 2];
        }
    }

    for (int i = 0; i < n; i++)
        cout << evenDp[i] << " " << oddDp[i] << endl;
}
