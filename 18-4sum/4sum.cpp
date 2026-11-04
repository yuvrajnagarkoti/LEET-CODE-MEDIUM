class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int j=n-1;
            while(j > i+2)
            {
                
                int low=i+1;
                int high=j-1;
                while(low < high)
                {
                    long long sum = 1LL*nums[i] + nums[j] + nums[low] + nums[high];

                    if(sum == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;

                        while(low < high && nums[low] == nums[low-1])
                            low++;
                        while(low < high && nums[high] == nums[high+1])
                            high--;
                        
                    }
                    else if(sum > target)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
                j--;
                while(j>i+2 && nums[j] == nums[j+1])
                    j--;
            }
        }
        return ans;
    }
};