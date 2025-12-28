class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        map<int,int> mpp;
        mpp[0] = 1;
        int psum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            psum += nums[i];
            int rem = psum % k;
            if (rem < 0)
                rem += k;   // normalize negative remainder

            if (mpp.find(rem) != mpp.end())
            {
                count += mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};