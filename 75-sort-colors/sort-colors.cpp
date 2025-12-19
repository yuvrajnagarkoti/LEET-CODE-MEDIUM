class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int white=0,blue=0;
        int r=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                nums[r++]=0;
            
            else if(nums[i] == 1)
                white++;
            else
                blue++;
        }
        while(white)
        {
            nums[r++] = 1;
            white--;
        }
        while(blue)
        {
            nums[r++] = 2;
            blue--;
        }
    }
};