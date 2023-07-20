bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), compare);
        int n = points.size(), res = 1;
        int prevEnd = points[0][1], presentStart;

        for (int i = 1; i < n; i++)
        {
            presentStart = points[i][0];

            if (presentStart > prevEnd)
            {
                res++;
                prevEnd = points[i][0];
            }
        }

        return res;
    }
};