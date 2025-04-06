class Solution {
public:
    int maxDepth(string s)
    {
        int i,max=0,count=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                count++;
                if(count>max)
                {
                    max=count;
                }
            }
            else if(s[i] == ')')
            {
                count--;
            }
        }
        return max;
    }
};