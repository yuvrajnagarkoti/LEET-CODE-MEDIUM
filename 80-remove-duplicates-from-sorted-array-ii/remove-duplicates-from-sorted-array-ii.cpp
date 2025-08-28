class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        unordered_map<int,int> count;
        for (int x : nums)
            count[x]++;

        sort(nums.begin(), nums.end());
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            if (count[val] > 0)
            {
                int allowed = min(2, count[val]);
                while (allowed--)
                {
                    nums[k++] = val;
                }
                count[val] = 0;
            }
        }
        return k;
    }
};