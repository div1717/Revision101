class Solution
{
public:
    int maxArea(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1, res = 0;

        while (start < end)
        {
            res = max(res, ((end - start) * min(nums[start], nums[end])));
            if (nums[start] > nums[end])
                end--;
            else if (nums[start] < nums[end])
                start++;
            else if (nums[start] == nums[end])
                start++, end--;
        }

        return res;
    }
};