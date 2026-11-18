class Solution
{
    public:

    void rec(vector<int> count,int &ans)
    {
        ans++;
        for(int i=0;i<26;i++)
        {
            if(count[i] <= 0)
                continue;

            count[i]--;
            rec(count,ans);
            count[i]++;
        }
    }

    int numTilePossibilities(string tiles)
    {
        vector<int> count(26,0);
        int ans=0;

        for(int i=0;i<tiles.length();i++)
        {
            count[tiles[i]-'A']++;
        }

        rec(count,ans);
        return ans-1;
    }
};