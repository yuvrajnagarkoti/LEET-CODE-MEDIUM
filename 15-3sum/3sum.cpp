class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]+nums[i] == 0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while( j<k && nums[j-1] == nums[j])
                    {
                        j++;
                    }
                    while( k>j && nums[k+1] == nums[k])
                    {
                        k--;
                    }
                }
                else if(nums[j]+nums[k]+nums[i] > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};