class Solution
{
    public:

    string ext(string s,int i)
    {
        string ans="";
        while(i<s.length() && s[i] != ' ')
        {
            ans.push_back(s[i]);
            i++;
        }

        return ans;
    }
    string reverseWords(string s)
    {
        int i=0,n=s.length();
        vector<string> words;
        while(i<n)
        {
            if(s[i] == ' ')
                i++;
            else
            {
                string temp = ext(s,i);
                i = i + temp.size();

                words.push_back(temp);
            }
        }

        string ans="";
        i=words.size()-1;
        while(i>0)
        {
            ans += words[i];
            ans.push_back(' ');
            i--;
        }
        if(words.size() > 0)
            ans += words[0];
        return ans;
    }
};