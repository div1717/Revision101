class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, int> mpp;
        int i = 0;
        for (auto &str : strs)
        {
            string word = str;
            sort(word.begin(), word.end());

            if (mpp.find(word) == mpp.end())
                mpp[word] = i, i++;
        }

        vector<vector<string>> res;

        for (auto str : strs)
        {
            string word = str;
            sort(str.begin(), str.end());

            res[mpp[word]].push_back(word);
        }

        return res;
    }
};