bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &nums)
    {
        sort(nums.begin(), nums.end(), compare);
        int n = nums.size(), res = 0;
        int prevEnd = nums[0][1], presentStart;

        for (int i = 1; i < n; i++)
        {
            presentStart = nums[i][0];

            if (presentStart < prevEnd)
            {
                res++;
                continue;
            }
            else
                prevEnd = nums[i][1];
        }

        return res;
    }
};