class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int i,t1,t2,t3;
        t1=t2=t3=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                t1++;
            else if(nums[i] == 1)
                t2++;
            else
                t3++;
        }
        i=0;
        while(t1 > 0)
        {
            nums[i++] = 0;
            t1--;
        }
        while(t2 > 0)
        {
            nums[i++] = 1;
            t2--;
        }
        while(t3 > 0)
        {
            nums[i++] = 2;
            t3--;
        }
    }
};