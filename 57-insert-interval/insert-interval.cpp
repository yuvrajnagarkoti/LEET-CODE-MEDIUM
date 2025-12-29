class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        int low=intervals[0][0];
        int high=intervals[0][1];
        for(int i=1;i<n;i++)
        {

            int l1=intervals[i][0];
            int h1=intervals[i][1];
            if(high < l1)
            {
                ans.push_back({low,high});
                low=l1;
                high=h1;
            }
            else
            {
                low=min(low,l1);
                high=max(high,h1);
            }
        }
        ans.push_back({low,high});
        return ans;
    }
};