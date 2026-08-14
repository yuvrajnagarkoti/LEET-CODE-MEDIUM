class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> pref(n,0);
        vector<int> postf(n,0);
        int temp=1;
        for(int i=0;i<n;i++)
        {
            pref[i]=temp;
            temp = temp * nums[i];
        }
        temp=1;
        for(int i=n-1;i>=0;i--)
        {
            postf[i]=temp;
            temp = temp * nums[i];
        }

        for(int i=0;i<n;i++)
        {
            pref[i] = pref[i]*postf[i];
        }
        return pref;
    }
};