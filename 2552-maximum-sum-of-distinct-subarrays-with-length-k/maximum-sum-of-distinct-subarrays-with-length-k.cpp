class Solution
{
    public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        long long sum=0,ans=0;
        int left,right,n=nums.size();
        set <int> s;
        left=0;
        for(int right=0;right<n;right++)
        {
            while( s.find(nums[right])!=s.end() || s.size()==k)
            {
                s.erase(nums[left]);
                sum-=nums[left++];
            }
            s.insert(nums[right]);
            sum+=nums[right];
            if( s.size() == k)
            {
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};
