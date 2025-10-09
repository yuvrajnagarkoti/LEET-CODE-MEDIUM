class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        long num = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i < s.size()) {
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }
        }

        while (i < s.size() && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
            if (num * sign >= INT_MAX) return INT_MAX;
            if (num * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(num * sign);
    }
};
