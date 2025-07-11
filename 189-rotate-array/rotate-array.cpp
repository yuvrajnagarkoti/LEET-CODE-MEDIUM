class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int i,j,n = nums.size();
        k=k%n;
        vector<int> temp(k);
        int t=0;
        for(i=n-k;i<n;i++)
        {
            temp[t++]=nums[i];
        }
        for(i=n-k,j=n-1 ; i>0 ;i--,j--)
        {
            nums[j]=nums[i-1];
        }

        for(i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
    }
};