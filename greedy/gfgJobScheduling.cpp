static bool compare(Job &a, Job &b)
{
    return a.profit > b.profit;
}
// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].dead);

    vector<int> scheduledArray(maxDeadline + 1, -1);
    int jobsDone = 0, totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int profit = arr[i].profit, dead = arr[i].dead;
        for (int j = dead; j > 0; j--)
        {
            if (scheduledArray[j] == -1)
            {
                scheduledArray[j] = profit;
                jobsDone++, totalProfit += profit;
                break;
            }
        }
    }

    return {jobsDone, totalProfit};
}