class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> mpp(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            mpp[tasks[i]-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(mpp[i] > 0)
            {
                pq.push(mpp[i]);
            }
        }
        int ans=0;
        while( !pq.empty() )
        {
            vector<int> temp;
            for(int i=0;i<=n;i++)
            {
                if( !pq.empty() )
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]-1 > 0)
                    pq.push(temp[i]-1);
            }
            if(pq.empty())
            {
                ans += temp.size();
            }
            else
            {
                ans += n+1;
            }
        }
        return ans;
    }
};