class Solution
{
public:
    double myPow(double x, int n)
    {
        long long power = n;  // Use long long to prevent overflow
        if (power < 0)
        {
            x = 1 / x;
            power = -power;
        }
        double result = 1;
        while (power)
        {
            if (power % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            power /= 2;
        }
        return result;
    }
};
