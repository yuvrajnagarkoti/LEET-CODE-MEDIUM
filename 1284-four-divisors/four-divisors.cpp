class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int ans=0;
        for(auto num:nums)
        {
            int count=0;
            int sum=0;
            for(int i=1;i<=sqrt(num);i++)
            {
                if(num%i == 0)
                {
                    int fnum=i;
                    int snum=num/i;
                    if(fnum == snum)
                    {
                        count++;
                    }
                    else
                    {
                        count=count+2;
                    }
                    sum=sum+fnum+snum;
                    if(count >4)
                    {
                        break;
                    }
                }
            }
            if(count == 4)
            {
                ans+=sum;
            }
        }
        return ans;
    }
};