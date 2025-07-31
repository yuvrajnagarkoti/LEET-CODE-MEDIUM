class Solution {
public:
    string sortVowels(string s) 
    {
        int i;
        vector<char> count;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ||
               s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                count.push_back(s[i]);
            }
        }
        sort( count.begin(),count.end());
        int k=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ||
               s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                    s[i] = count[k++];
            }
        }
        return s;
    }
};