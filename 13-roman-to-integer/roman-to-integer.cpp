class Solution
{
public:
    int value(char ch)
    {
        switch (ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    
    int romanToInt(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int curr = value(s[i]);
            int next = (i + 1 < s.length()) ? value(s[i + 1]) : 0;

            if (curr < next)
                sum -= curr;
            else
                sum += curr;
        }
        return sum;
    }
};
