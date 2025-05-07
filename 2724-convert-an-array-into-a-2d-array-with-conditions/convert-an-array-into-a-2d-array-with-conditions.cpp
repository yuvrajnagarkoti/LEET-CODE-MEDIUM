class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        int maxVal = INT_MIN;
        // Find the maximum value in nums
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        // Count frequency of each number
        vector<int> count(maxVal + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<vector<int>> ans;
        // Build the matrix row by row
        while (true)
        {
            vector<int> temp;
            bool flag = false;
            for (int i = 0; i < count.size(); i++)
            {
                if (count[i] > 0)
                {
                    temp.push_back(i);
                    count[i]--;
                    flag = true;
                }
            }
            if (!flag) break;
            ans.push_back(temp);
        }
        return ans;
    }
};
