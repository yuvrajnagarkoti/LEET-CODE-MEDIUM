class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, flag = 1;
        long sum = 0;
        while (i < s.length() && s[i] == ' ')
            i++;

        // Handle optional '+' or '-'
        if (i < s.length())
        {
            if (s[i] == '-')
            {
                flag = -1;
                i++;
            }
            else if (s[i] == '+')
            {
                i++;
            }
        }

        // Read digits with overflow check
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';
            if (sum > (INT_MAX - digit) / 10)
            {
                return (flag == 1) ? INT_MAX : INT_MIN;
            }
            sum = sum * 10 + digit;
            i++;
        }
        return (int)(sum * flag);
    }
};
