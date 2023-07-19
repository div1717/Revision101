class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        map<int, int> mpp;
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            int n1 = nums1[i], n2 = nums2[i];
            mpp[n1]++;
            mpp[n2]++;

            res[i] = ((i + 1) * 2) - mpp.size();
        }
        return res;
    }
};