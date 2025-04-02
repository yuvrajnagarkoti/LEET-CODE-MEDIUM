class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int cand1 = -1, cand2 = -1, count1 = 0, count2 = 0;
        // Step 1: Find potential majority candidates
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        // Step 2: Verify actual counts
        count1 = count2 = 0;
        for (int num : nums)
        {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        vector<int> result;
        if (count1 > n / 3) result.push_back(cand1);
        if (count2 > n / 3) result.push_back(cand2);

        return result;
    }
};