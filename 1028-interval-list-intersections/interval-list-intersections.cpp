class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2)
    {
        vector<vector<int>> ans;
        int i=0, j=0;

        while (i < list1.size() && j < list2.size())
        {
            int start = max(list1[i][0], list2[j][0]);
            int end   = min(list1[i][1], list2[j][1]);

            if (start <= end)
                ans.push_back({start, end});

            if (list1[i][1] < list2[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};