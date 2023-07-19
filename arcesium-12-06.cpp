#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> mpp;
    for (int i = 0; i < s1.size(); i++)
    {
        mpp[s1[i]] = i % 2;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        mpp[s2[i]] -= (i % 2);
        if (mpp[s2[i]] == 0)
            mpp.erase(s2[i]);
    }
    if (mpp.size() == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}