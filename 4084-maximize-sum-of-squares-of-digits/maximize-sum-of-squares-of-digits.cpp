class Solution {
public:
    string maxSumOfSquares(int num, int sum)
    {
        string s = "";
        while(s.length() < num)
        {
            if(sum >= 9)
            {
                s.push_back('9');
                sum -= 9;
            }
            else
            {
                s.push_back(sum + '0');
                sum = 0;
            }
        }
        if(sum != 0)
            return "";
        return s;
    }
};