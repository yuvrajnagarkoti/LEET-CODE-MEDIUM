class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int> n1;
        vector<int> n2;
        int p=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < pivot)
                n1.push_back(nums[i]);
            else if(nums[i] == pivot)
                p++;
            else
                n2.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i=0;i<n1.size();i++)
        {
            ans.push_back(n1[i]);
        }
        while(p--)
            ans.push_back(pivot);
        for(int i=0;i<n2.size();i++)
        {
            ans.push_back(n2[i]);
        }
        return ans;
    }
};