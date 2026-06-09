class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        long long mn = nums[0];
        long long mx = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(mn > nums[i])
                mn = nums[i];
            if(mx < nums[i])
                mx = nums[i];
        }
        long long ans = k*(mx-mn);
        return ans;
    }
};