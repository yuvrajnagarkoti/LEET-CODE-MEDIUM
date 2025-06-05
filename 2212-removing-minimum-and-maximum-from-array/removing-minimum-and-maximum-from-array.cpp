class Solution
{
public:
    int minimumDeletions(vector<int>& nums)
    {
        int n = nums.size();
        int min1 = 0, max1 = 0;
        int minimum = nums[0], maximum = nums[0];
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > maximum)
            {
                maximum = nums[i];
                max1 = i;
            }
            if(nums[i] < minimum)
            {
                minimum = nums[i];
                min1 = i;
            }
        }

        // Deleting both from the front
        int option1 = max(min1, max1) + 1;
        // Deleting both from the back
        int option2 = max(n - min1, n - max1);
        // One from front, one from back
        int option3 = min1 + 1 + (n - max1);
        int option4 = max1 + 1 + (n - min1);
        return min({option1, option2, option3, option4});
    }
};
