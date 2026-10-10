class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> post(n,0);
        int sum=1;
        for(int i=n-1;i>=0;i--)
        {
            post[i] = sum;
            sum *= nums[i];
        }
        sum=1;
        for(int i=0;i<n;i++)
        {
            post[i] = post[i] * sum;
            sum *= nums[i];
        }

        return post;
    }
};