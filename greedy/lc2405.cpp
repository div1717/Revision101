// class Solution
// {
// public:
//     int partitionString(string s)
//     {
//         map<char, int> mpp;
//         int res = 0, start = 0;

//         for (int i = 0; i < s.length(); i++)
//         {
//             mpp[s[i]]++;
//             if (mpp.size() != (i - start + 1))
//             {
//                 res++;
//                 start = i;
//                 mpp.clear();
//                 mpp[s[i]]++;
//             }
//         }

//         return res;
//     }
// };

class Solution
{
public:
    int partitionString(string s)
    {
        map<char, int> mpp;
        int res = 0, start = INT_MIN;

        for (char c = 's'; c <= 'z'; c++)
            mpp[c] = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (mpp[s[i]] > start)
            {
                res++;
                start = i;
            }
            mpp[s[i]] = i;
        }

        return res + 1;
    }
};