class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;

        int idxG = 0, idxS = 0;

        while (idxG < g.size() && idxS < s.size())
        {
            if (g[idxG] <= s[idxS])
                res++, idxG++, idxS++;
            else if (g[idxG] > s[idxS])
                while (idxS < s.size() && g[idxG] > s[idxS])
                    idxS++;
        }

        return res;
    }
};