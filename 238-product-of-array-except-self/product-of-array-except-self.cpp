class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int i=0,n=nums.size();
        vector<int> leftsub(n,0);
        vector<int> rightsub(n,0);
        vector<int> ans(n,0);
        leftsub[0]=1;
        leftsub[1]=nums[0];
        rightsub[n-1]=1;
        rightsub[n-2]=nums[n-1];

        for(i=1;i<n;i++)
        {
            leftsub[i]=nums[i-1]*leftsub[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            rightsub[i]=nums[i+1]*rightsub[i+1];
        }
        
        ans[0]=rightsub[0];
        ans[n-1]=leftsub[n-1];
        for(i=1;i<n-1;i++)
        {
            ans[i]=leftsub[i]*rightsub[i];
        }
        return ans;
    }
};