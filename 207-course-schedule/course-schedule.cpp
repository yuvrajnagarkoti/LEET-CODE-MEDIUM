class Solution {
public:

    bool dfs(int node, map<int,set<int>>& mpp, 
             vector<int>& vis, vector<int>& path)
    {
        vis[node] = 1;
        path[node] = 1;

        for(auto it : mpp[node])
        {
            if(!vis[it])
            {
                if(dfs(it, mpp, vis, path))
                    return true;
            }
            else if(path[it])
            {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool canFinish(int num, vector<vector<int>>& prereq)
    {
        map<int,set<int>> mpp;

        for(int i = 0; i < prereq.size(); i++)
        {
            int left = prereq[i][0];
            int right = prereq[i][1];

            mpp[right].insert(left);
        }

        vector<int> vis(num, 0);
        vector<int> path(num, 0);

        for(int i = 0; i < num; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, mpp, vis, path))
                    return false;
            }
        }

        return true;
    }
};