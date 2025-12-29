class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        int i=1,n=intervals.size();
        int low=intervals[0][0];
        int high=intervals[0][1];
        while( i < n )
        {
            int l1=intervals[i][0];
            int h1=intervals[i][1];
            if( high < l1 )
            {
                ans.push_back( {low,high} );
                low=l1;
                high=h1;
            }
            else
            {
                low=min(low,l1);
                high=max(high,h1);
            }
            i++;
        }
        ans.push_back( {low,high} );
        return ans;
    }
};