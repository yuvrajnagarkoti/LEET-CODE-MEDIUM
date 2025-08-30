class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+k;j>i;j--)
            {
                if(j<nums.size() && nums[i] == nums[j] && abs(i-j)<=k)
                    return true;                
            }
        }
        return false;
    }
};