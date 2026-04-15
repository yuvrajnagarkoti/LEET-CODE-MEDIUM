class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex)
    {
        map<string,vector<int>> mpp;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            mpp[words[i]].push_back(i);
        }
        if(mpp.find(target) == mpp.end())
            return -1;
        
        int ans=INT_MAX;
        for(int i=0;i<mpp[target].size();i++)
        {
            ans = min(ans, abs(mpp[target][i]-startIndex));
            if(startIndex < mpp[target][i])
            {
                ans = min(ans, (startIndex-0)+(n-mpp[target][i]));
            }
            else
            {
                ans = min(ans, (mpp[target][i]-0)+(n-startIndex));
            }
        }
        return ans;
    }
};