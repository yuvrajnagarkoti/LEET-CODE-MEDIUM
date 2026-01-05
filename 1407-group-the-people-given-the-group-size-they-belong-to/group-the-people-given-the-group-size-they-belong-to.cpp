class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        int n=groupSizes.size();
        vector<vector<int>> count(n+1);
        for(int i=0;i<n;i++)
        {
            count[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for(int i=1;i<count.size();i++)
        {
            int j=0;
            while(j<count[i].size())
            {
                vector<int> t1;
                int cnt=i;
                while(cnt--)
                {
                    t1.push_back(count[i][j]);
                    j++;
                }
                ans.push_back(t1);
            }
        }
        return ans;
    }
};