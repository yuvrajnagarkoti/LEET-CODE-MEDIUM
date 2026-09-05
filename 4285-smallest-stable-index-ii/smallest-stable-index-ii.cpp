class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        vector<int> temp(nums.size(),0);
        temp[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
            {
                temp[i] = min(temp[i+1],nums[i]);
            }

        int m=nums[0];
        for(int i=0;i<nums.size();i++)
            {
                m = max(m,nums[i]);
                if(m-temp[i] <= k)
                    return i; 
            }
        return -1;
    }
};