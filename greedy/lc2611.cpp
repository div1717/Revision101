class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int n = rewards1.size();
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < n; i++)
            maxHeap.push({(reward1[i] - reward2[i]), i});

        int sum = 0, int cnt = 0;

        while (maxHeap.size())
        {
            int i = maxHeap.top().second;
            maxHeap.pop();

            if (cnt < k)
            {
                sum += reward1[i], cnt++;
            }
            else
                sum += reward2[i];
        }

        return sum;
    }
};