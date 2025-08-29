class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k=k%nums.size();
        if(k==0)
            return;
        vector<int> n(nums.size(),0);
        int i=0,i1=0,j=nums.size()-k;
        while(i<nums.size())
        {
            if( j<nums.size())
            {
                n[i]=nums[j++];
            }
            else
            {
                n[i]=nums[i1++];
            }
            i++;
        }
        for(int i=0;i<nums.size();i++)
            nums[i]=n[i];
    }
};