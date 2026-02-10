class Solution {
public:
    int longestBalanced(vector<int>& nums)
    {
        int ans = 0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map <int,int> empp;
            unordered_map <int,int> ompp;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2 == 0)
                    empp[nums[j]]++;
                else
                    ompp[nums[j]]++;
                
                if(empp.size() == ompp.size() )
                {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};