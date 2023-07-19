class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        int reachable = nums[0], current = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (i == current)
            {
                res++;
                current = reachable;
            }
            reachable = max(reachable, i + nums[i]);
        }

        return res;
    }
};