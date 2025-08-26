class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int i,j,k,n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        i=0;
        while( i<n )
        {
            j=i+1;
            k=n-1;
            while( j < k )
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<n && nums[j-1] == nums[j])
                        j++;
                }
                else if( nums[i]+nums[j]+nums[k] > 0)
                {
                    k--;
                    while( k>j && nums[k+1] == nums[k])
                        k--;
                }
                else if( nums[i]+nums[j]+nums[k] < 0)
                {
                    j++;
                    while( j < k && nums[j-1] == nums[j])
                        j++;
                }
            }
            i++;
            while(i<n && nums[i-1] == nums[i])
                i++;
        }
        return ans;
    }
};