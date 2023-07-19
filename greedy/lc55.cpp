class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = -1, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > reachable)
                return false;
            reachable = max(reachable, i + nums[i]);
        }

        return reachable >= n - 1 ? 1 : 0;
    }
};