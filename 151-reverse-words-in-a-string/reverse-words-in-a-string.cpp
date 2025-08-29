class Solution {
public:
    string reverseWords(string s)
    {
        vector<string> ans;
        int i=0;
        int j=0;
        while(i<s.length())
        {
            if(s[i] == ' ')
                i++;
            else
            {
                j=i;
                while(j<s.length() && s[j] != ' ')
                {
                    j++;
                }
                string temp = s.substr(i,j-i);
                ans.push_back(temp);
                i=j;
            }
        }
        s="";
        for(i=ans.size()-1;i>0;i--)
        {
            s+= ans[i]+" ";
        }
        s+=ans[i];
        return s;
    }
};