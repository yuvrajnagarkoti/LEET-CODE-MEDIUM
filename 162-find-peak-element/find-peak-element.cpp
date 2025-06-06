class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        int i,n=a.size(),peak=0;
        if(n<= 1)
            return 0;
        if( a[0] > a[1])
            return 0;
        if( a[n-1] > a[n-2])
            return n-1;
        for(i=1;i<n-1;i++)
        {
            if( a[i-1] < a[i] && a[i] > a[i+1])
            {
                peak = i;
                break;
            }
        }
        return peak;
    }
};