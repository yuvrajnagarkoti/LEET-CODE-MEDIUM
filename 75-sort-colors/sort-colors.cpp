class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int i=0;
        int red=0;
        int white=0;
        int blue=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                red++;
            else if(nums[i] == 1)
                white++;
            else
                blue++;
        }
        i=0;
        while(red)
        {
            nums[i++] = 0;
            red--;
        }
        while(white)
        {
            nums[i++] = 1;
            white--;
        }
        while(blue)
        {
            nums[i++] = 2;
            blue--;
        }
    }
};