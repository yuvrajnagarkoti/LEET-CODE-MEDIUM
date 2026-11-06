class Solution
{
public:

    bool static compare(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries)
    {
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), compare);

        vector<int> ans(queries.size(), 0);
        vector<int> freq(n+1, 0);

        int left = 0, right = 0;
        int cnt = 0;

        for(int i = 0; i < q.size(); i++)
        {
            int start = q[i].first - x;
            int end = q[i].first;

            while(right < logs.size() && logs[right][1] <= end)
            {
                int id = logs[right][0];

                if(freq[id] == 0)
                    cnt++;

                freq[id]++;
                right++;
            }

            while(left < right && logs[left][1] < start)
            {
                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0)
                    cnt--;

                left++;
            }

            ans[q[i].second] = n - cnt;
        }

        return ans;
    }
};