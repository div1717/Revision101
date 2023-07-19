// // user_name -> divyansh_17
// // year -> 2022
// // college -> IIITP
// class Solution{
// public:
//     vector<vector<int>> merge(vector<vector<int>> &in){
//         int n = in.size(), i = 1;
//         vector<vector<int>> ans;

//         if (!n) return ans;          // base case
//         sort(in.begin(), in.end());  // sort for having consecutive merging intervals
//         vector<int> temp = in[0];    // store the first pair for comparison

//         for (int i = 1; i < n; i++){
//             // if the closing of temp pair is greater than the opening of the next pair it means there are merging intervals , but now                the closing of second intervals can be greater or less than the closing of temp pair so we store the maximum of it in                  the closing value of temp pair
//             if (in[i][0] <= temp[1]) temp[1] = max(temp[1], in[i][1]);
//             // else we pushback the temp pair in ans and update the temp for the next pair in interval that was not a merging interval
//             else ans.push_back(temp), temp = in[i];
//         }
//         // one last pair will be left in which will have no next pairs to compare so just simply push it in
//         ans.push_back(temp);
//         return ans;
//     }
// };

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        pair<int, int> temp = {intervals[0][0], intervals[0][1]};

        vector<vector<int>> res;

        for (int i = 1; i < n; i++)
        {
            cout << temp.first << " " << temp.second << endl;
            if (temp.second >= intervals[i][0])
            {
                while (i < n && temp.second >= intervals[i][0])
                {
                    cout << i << endl;
                    temp.second = max(temp.second, intervals[i][1]);
                    i++;
                }
            }
            else
            {
                res.push_back({temp.first, temp.second});
                temp = {intervals[i][0], intervals[i][1]};
            }
        }

        res.push_back({temp.first, temp.second});
        return res;
    }
};
