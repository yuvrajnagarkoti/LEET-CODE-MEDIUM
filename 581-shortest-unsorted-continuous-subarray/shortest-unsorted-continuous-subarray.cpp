class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        if(nums.size() == 1)
            return 0;
        vector<int> n1(nums.begin(),nums.end());
        sort(n1.begin(),n1.end());
        int low=0,high=n1.size()-1;

        while( low <= high )
        {
            if(n1[low]!=nums[low] && n1[high]!=nums[high])
            {
                break;
            }
            if( n1[low]==nums[low] )
                low++;
            if( low <= high && n1[high]==nums[high] )
                high--;
        }
        return high-low+1;
    }
};