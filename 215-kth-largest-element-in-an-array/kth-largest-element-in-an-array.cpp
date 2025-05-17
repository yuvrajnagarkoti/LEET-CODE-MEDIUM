class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int min = nums[0];
        int max = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(min > nums[i])
                min=nums[i];
            if(max < nums[i])
                max=nums[i];
        }
        vector <int> count(max-min+1 ,0);

        for (int num : nums)
        {
            count[num-min]++;
        }

        int remaining = k;
        for (int i = count.size()-1 ; i>=0 ; i--)
        {
            remaining -= count[i];
            if (remaining <= 0)
            {
                return i + min;
            }
        }
        return -1;   
    }
};