class Solution {
public:
    bool isHappy(int n)
    {
        map<long long,int> mpp;
        mpp[n]++;
        while(n!= 1)
        {
            long long sum=0;
            int temp=n;
            while(temp>0)
            {
                int t=temp%10;
                temp=temp/10;
                sum=sum+ (t*t);
            }
            mpp[sum]++;
            n=sum;
            if(mpp[sum] == 2)
                return false;
        }
        return true;
    }
};