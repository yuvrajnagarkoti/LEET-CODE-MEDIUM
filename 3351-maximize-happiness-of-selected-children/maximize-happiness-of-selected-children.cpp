class Solution
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.rbegin(),happiness.rend());
        int c=0;
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            if(happiness[i]-c > 0)
                ans+= happiness[i]-c;
            c++;
        }
        return ans;
    }
};