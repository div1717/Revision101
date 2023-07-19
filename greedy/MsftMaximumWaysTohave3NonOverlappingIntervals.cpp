#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> startings(n), endings(n);

    for (int i = 0; i < n; i++)
        cin >> startings[i];
    for (int i = 0; i < n; i++)
        cin >> endings[i];

    vector<pair<int, int>> startEnd;
    for (int i = 0; i < n; i++)
        startEnd.push_back({startings[i], endings[i]});

    startings.push_back(INT_MAX);
    startings.push_back(INT_MIN);

    endings.push_back(INT_MAX);
    endings.push_back(INT_MIN);

    sort(startings.begin(), startings.end());
    sort(endings.begin(), endings.end());
    sort(startEnd.begin(), startEnd.end());
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int s = startEnd[i].first, e = startEnd[i].second;
        // cout << s << " " << e << endl;

        int a = lower_bound(endings.begin(), endings.end(), s) - endings.begin();
        int b = upper_bound(startings.begin(), startings.end(), e) - startings.begin();

        int lessThanStartInEndings = lower_bound(endings.begin(), endings.end(), s) - endings.begin() - 1;
        int moreThanEndInStartings = n - (upper_bound(startings.begin(), startings.end(), e) - startings.begin()) + 1;

        // cout<<lessThanStartInEndings<<" "<<moreThanEndInStartings<<endl;

        res += (lessThanStartInEndings * moreThanEndInStartings);
    }

    cout << res << endl;
}