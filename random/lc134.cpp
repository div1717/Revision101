class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = -1, = gas.size();
        for (int i = 0; i < n; i++)
            if (gas[i] > cost[i])
                start = i;

        int currFuel = gas[start], dummyStart = start;
        for (int i = start + 1; i < 2 * n; i++)
        {
            int idx = i % n;
            if (dummyStart == start)
                return start;

            if (idx == 0)
                currFuel -= cost[n - 1];
            else
                currFuel -= cost[idx - 1];
            currFuel += gas[idx];
        }

        return -1;
    }
};