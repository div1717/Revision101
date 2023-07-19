class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int res = 0;
        map<string, int> mpp;
        for (auto word : words)
            mpp[word]++;

        // checks for a word with same chars that comes only once as
        // it can be the middle of the palindrome.
        int flag = 0;
        for (auto it : words)
        {
            if (it[0] == it[1])
            {
                int cnt = mpp[it];
                if (cnt % 2 == 1)
                {
                    flag = 1;
                    res += (cnt - 1) * 2;
                }
                else
                    res += cnt * 2;
                mpp.erase(it);
            }
            else
            {
                string word = it;
                int wordCnt = mpp[word];

                reverse(it.begin(), it.end());
                string rev = it;
                int revCnt = 0;

                if (mpp.find(rev) != mpp.end())
                {
                    revCnt = mpp[rev];
                    mpp.erase(word);
                    mpp.erase(rev);
                }

                int palindromicOccurence = min(wordCnt, revCnt);
                res += (palindromicOccurence * 2 * 2);
            }
        }

        return flag ? res + 2 : res;
    }
};