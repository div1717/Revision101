class Solution
{
public:
    using ll = long long;
    int minimumPartition(string s, int k)
    {
        ll i = 0, cnt = 0, n = s.size();
        string temp = "";

        while (i < n)
        {
            temp += s[i];
            int num = stoll(temp);

            if (num > k)
                cnt++, temp = s[i];

            if ((s[i] - '0') > k)
                return -1;
            i++;
        }

        if (stoll(temp) <= k)
            cnt++;

        return cnt;
    }
};