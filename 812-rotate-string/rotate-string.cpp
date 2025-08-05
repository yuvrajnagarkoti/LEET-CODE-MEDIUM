class Solution {
public:
    bool rotateString(string s, string goal)
    {
        if(s.length() != goal.length())
            return false;
        int i=0,n=s.length();
        while( i < n)
        {
            if(s == goal)
                return true;
            string temp = s.substr(1,n-1);
            temp = temp + s[0];
            s=temp;
            i++;
        }
        return false;
    }
};