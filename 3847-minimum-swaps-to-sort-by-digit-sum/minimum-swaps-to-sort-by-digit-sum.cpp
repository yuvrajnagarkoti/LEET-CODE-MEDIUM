class Solution
{
public:
    int digitsum(int num){
        int v=0;
        while(num>0){
            v+=num%10;
            num=num/10;
        }
        return v;
    }
    int minSwaps(vector<int>& nums)
    {
        int n=nums.size();
        vector<array<int, 3>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({digitsum(nums[i]), nums[i], i}); // {digitsum, nums_value, index}
        }
        sort(vec.begin(), vec.end());
        int res=0;
        for(int i=0;i<n;i++)
        {
            int ind=vec[i][2];
            if(ind!=i)
            {
                res+=1;
                swap(vec[i], vec[ind]);
                i--;
            }
        }
        return res;
    }
};