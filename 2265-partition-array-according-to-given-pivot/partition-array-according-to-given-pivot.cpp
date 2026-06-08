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
        
        while(p--)
            n1.push_back(pivot);
        n1.insert(n1.end(),n2.begin(),n2.end());
        return n1;
    }
};