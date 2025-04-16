class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i = 0;
        int n = nums.size();
        while (i < n - 1)
        {
            if (nums[i] == 0)
                return false;
            int maxReach = i + nums[i];
            if (maxReach >= n - 1)
                return true;
            int nextIndex = i;
            for (int j = i + 1; j <= maxReach; j++)
            {
                if (j + nums[j] > nextIndex + nums[nextIndex])
                {
                    nextIndex = j;
                }
            }
            if (nextIndex == i)
                return false;
            i = nextIndex;
        }
        return true;
    }
};
