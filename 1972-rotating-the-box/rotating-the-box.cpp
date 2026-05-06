class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid)
    {
        int n=boxGrid.size(),m=boxGrid[0].size();
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(boxGrid[j][i] == '#')
                {
                    int k=i+1;
                    while(k<m && boxGrid[j][k] == '.')
                    {
                        boxGrid[j][k-1] = '.';
                        boxGrid[j][k] = '#';
                        k++;
                    }
                }
            }
        }
        vector<vector<char>> ans(m);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                ans[i].push_back(boxGrid[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        {
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};