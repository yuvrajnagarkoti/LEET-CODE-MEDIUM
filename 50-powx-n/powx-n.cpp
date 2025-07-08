class Solution 
{
public:

    double helper(double x,int n)
    {
        if(n==0)    return 1;
        if(x==0)    return 0;
        double res = helper(x,n/2);
        res = res*res;
        if(n%2 != 0)
            res = res*x;
        return res;
    }

    double myPow(double x, int n)
    {
        double res = helper(x,n);
        if( n < 0)
        {
            res = 1/res;
        }
        return res;
    }
};