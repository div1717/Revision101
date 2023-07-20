class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        int n = nums.size();
        long long res = 0;

        for (int i = 0; i < n; i++)
            maxHeap.push(nums[i]);

        for (int i = 0; i < k; i++)
        {
            int num = maxHeap.top();
            maxHeap.pop();
            res += num;
            int newNum = ceil(double(num) / 3);
            maxHeap.push(newNum);
        }

        return res;
    }
};