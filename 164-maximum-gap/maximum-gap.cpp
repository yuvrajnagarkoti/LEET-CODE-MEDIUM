class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        int i,diff=INT_MIN;
        if(nums.size() <2) return 0;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-1;i++)
        {
            diff = max(diff, nums[i+1]-nums[i]);
        }
        return diff;
    }
};