class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int low=0,high=height.size()-1;
        int ans=0;
        while( low < high )
        {
            int temp=min(height[low],height[high]);
            if( temp*(high-low) > ans )
            {
                ans=temp*(high-low);
            }
            if(height[low] < height[high] )
                low++;
            else
                high--;
        }
        return ans;
    }
};