class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(nums[i] > 0)
            {
                int temp = nums[i]%10;
                nums[i]=nums[i]/10;
                ans.push_back(temp);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};