class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int i=0,j=nums.size()-1,flag = 0;
        vector<int> ans;
        while( i <= j )
        {
            if( nums[i] == target && nums[j] == target)
            {
                flag = 1;
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            else if( nums[i] == target)
            {
                j--;
            }
            else if( nums[j] == target)
            {
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        if(flag == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};