class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int flag=1;
            if ( ((i-k >=0)&&!(nums[i]>nums[i-k])) || ((i+k<nums.size())&&!(nums[i]>nums[i+k])) )
                flag=0;
            if(flag)
                sum+=nums[i];
        }
        return sum;
    }
};