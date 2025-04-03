class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int i,j,sum,count=0;
        for(i=0;i<nums.size();i++)
        {
            sum=nums[i];
            if(sum == k)
            {
                count++;
            }
            for(j=i+1;j<nums.size();j++)
            {
                sum=sum+nums[j];
                if(sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};