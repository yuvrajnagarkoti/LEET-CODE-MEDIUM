class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i = 0, j = 0, k = 0;
        while (i < nums.size() - 1)
        {
            int m = INT_MIN;
            int maxReach = i + nums[i];
            if (nums[i] == 0)
                return false;
            for (j = i + 1; j <= maxReach && j < nums.size(); j++)
            {
                if (m < j + nums[j])
                {
                    m = j + nums[j];
                    k = j;
                }
            }
            if (k == i)
                return false;
            i = k;
        }
        return true;
    }
};
