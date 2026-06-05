class Solution
{
    public:

    int check(int i)
    {
        string s = to_string(i);
        int n=s.length();
        if(n<3)
            return 0;
        
        int count=0;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]>s[i-1] && s[i]>s[i+1])
                count++;
            else if(s[i]<s[i-1] && s[i]<s[i+1])
                count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2)
    {
        int waviness=0;
        for(int i=num1;i<=num2;i++)
        {
            waviness += check(i);
        }
        return waviness;
    }
};