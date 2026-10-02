class Solution
{
    public:

    void RLE(string &s)
    {
        string temp="";
        int i=0,count=0,high=0;
        while(high<=s.length())
        {
            if(i<s.length() && s[i] == s[high])
            {
                count++;
                high++;
            }
            else
            {
                string t = to_string(count);
                temp = temp + t;
                temp.push_back(s[i]);
                i=high;
                high++;
                count=1;
            }

        }
        s = temp;
    }

    string countAndSay(int n)
    {
        string s="1";
        for(int i=2;i<=n;i++)
        {
            RLE(s);
        }

        return s;
    }
};