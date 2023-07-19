#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> in(n), out(n);

    for (int i = 0; i < n; i++)
        cin >> in[i];

    for (int i = 0; i < n; i++)
        cin >> out[i];

    int size = INT_MIN;
    for (auto it : out)
        size = max(size, it);

    vector<int> attendants(siz + 1, 0);

    for (int i = 0; i < n; i++)
    {
        attendants[in[i] - 1] += 1;
        attendants[out[i]] -= 1;
    }

    for (int i = 1; i < attendants.size(); i++)
        attendants[i] += attendants[i - 1];

    int maxGuests = 0, maxIndex = -1;

    for (int i = 0; i < size; i++)
        if (attendants[i] > maxGuests)
            maxGuests = attendants[i], maxIndex = i + 1;

    return {maxGuests, maxIndex};
}
