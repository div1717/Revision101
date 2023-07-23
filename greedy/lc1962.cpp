class Solution
{
public:
    int minStoneSum(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; i++)
            maxHeap.push(nums[i]);

        while (k--)
        {
            int num = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(num - (floor(double(num) / 2)));
        }

        while (maxHeap.size() > 0)
            res += maxHeap.top(), maxHeap.pop();

        return res;
    }
};
