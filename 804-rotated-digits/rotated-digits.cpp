class Solution
{
public:
    unordered_map <char,char> mpp = { {'2','5'},{'5','2'},{'6','9'},{'9','6'},{'0','0'},{'1','1'},{'8','8'} };

    int rotate(int i)
    {
        string s = to_string(i);
        for(int i=0;i<s.length();i++)
        {
            if(mpp.find(s[i]) == mpp.end())
                return 0;
            
            s[i]=mpp[s[i]];
        }
        int newint = stoi(s);

        if(i==newint)
            return 0;
        return 1;
    }
    int rotatedDigits(int n)
    {
        int count=0;
        for(int i=0;i<=n;i++)
        {
            count += rotate(i);
        }
        return count;
    }
};