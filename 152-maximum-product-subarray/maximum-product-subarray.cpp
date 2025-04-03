class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int i,j,ans,max=INT_MIN;
        for(i=0;i<nums.size();i++)
        {
            ans=nums[i];
            if(ans>max)
                max=ans;
            for(j=i+1;j<nums.size();j++)
            {
                ans=ans*nums[j];
                if( ans > max)
                    max=ans;
            }
        }
        return max;
    }
};