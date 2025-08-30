class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int reach=0;
        if(nums.size() == 1)
            return true;
        for(int i=0;i<nums.size();i++)
        {
            if(i > reach)
                return false;
            reach = max(nums[i]+i,reach);
        }
        return true;
    }
};