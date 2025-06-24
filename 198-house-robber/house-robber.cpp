class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int i,n=nums.size();
        int left=0,right=0;

        for(i=0;i<n;i++)
        {
            int temp = max ( left+nums[i] , right);
            left = right;
            right = temp;
        }
        return right;
    }
};