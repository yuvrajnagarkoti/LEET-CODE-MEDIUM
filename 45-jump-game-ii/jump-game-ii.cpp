class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jumps=0,l=0,r=0;
        while( r < nums.size()-1 )
        {
            int maxjump=0;
            for(int i=l;i<=r;i++)
            {
                maxjump=max(nums[i]+i,maxjump);
            }
            l=r+1;
            r=maxjump;
            jumps++;
        }
        return jumps;
    }
};
