class Solution
{
    public:
    set<string> st;

    void rec(string cur,vector<int> vis,string tiles)
    {
        st.insert(cur);
        int n=tiles.size();
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 1)
                continue;

            vis[i] = 1;
            cur.push_back(tiles[i]);
            rec(cur,vis,tiles);
            vis[i] = 0;
            cur.pop_back();
        }

    }

    int numTilePossibilities(string tiles)
    {
        
        vector<int> vis(tiles.size(),0);
        string cur="";
        
        rec(cur,vis,tiles);
        return st.size()-1;
    }
};