class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int> n1;
        int p=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < pivot)
                n1.push_back(nums[i]);
            else if(nums[i] == pivot)
                p++;
        }
        while(p--)
            n1.push_back(pivot);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > pivot)
                n1.push_back(nums[i]);
        }
        return n1;
    }
};