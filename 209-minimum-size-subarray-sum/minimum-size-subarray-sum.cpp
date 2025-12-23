class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int low=0,high=0; 
        int sum=0,n=nums.size(); 
        int minl=INT_MAX;
        while(high < n || sum >= target) 
        {
            if(sum >= target)
            {
                minl=min(minl,high-low);  
                sum=sum-nums[low];
                low++;
            }
            else
            {
                sum=sum+nums[high];
                high++;
            }
        }
        return minl == INT_MAX ? 0 : minl;
    }
};