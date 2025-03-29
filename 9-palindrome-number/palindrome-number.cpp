class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x<0)
            return false;
        long rev;
        int y = x;
        while (y>0)
        {
            rev = rev * 10 + y % 10;
            y/=10;
        }
        if (x==rev)
        {
            return true;
        }
        return false;
    }
};