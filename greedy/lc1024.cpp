class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        int min = 0, max = 0, res = 0;

        while (max < time)
        {
            for (int i = 0; i < clips.size(); i++)
            {
                int start = clips[i][0], end = clips[i][1];
                if (start <= min && end > max)
                    max = end;
            }

            if (min == max)
                return -1;
            min = max;
            res++;
        }

        return res;
    }
};