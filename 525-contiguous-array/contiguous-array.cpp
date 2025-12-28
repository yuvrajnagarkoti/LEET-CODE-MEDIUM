class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int ans=0;
        int c0=0,c1=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                c0++;
            else
                c1++;
            
            int dif=c0-c1;
            if(mpp.find(dif) != mpp.end())
            {
                ans=max(i-mpp[dif],ans);
            }
            else
                mpp[dif]=i;
        }
        return ans;
    }
};