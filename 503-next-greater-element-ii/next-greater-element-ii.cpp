class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int> stk;
        int n=nums.size()-1;
        for(int i=n;i>=0;i--)
        {
            stk.push(i);
        }

        vector<int> ans(n+1,0);
        for(int i=n;i>=0;i--)
        {
            while( !stk.empty() && nums[stk.top()] <= nums[i])
            {
                stk.pop();
            }
            if(stk.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = nums[stk.top()];
            }
            stk.push(i);
        }
        return ans;
    }
};