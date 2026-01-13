class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> ans(nums.size(),0);
        int low=0,high=nums.size()-1;
        int i=nums.size()-1;
        while(low<=high)
        {
            long long t1 = nums[low]*nums[low];
            long long t2 = nums[high]*nums[high];
            if(t1 > t2)
            {
                ans[i--]=t1;
                low++;
            }
            else
            {
                ans[i--]=t2;
                high--;
            }
        }
        return ans;
    }
};