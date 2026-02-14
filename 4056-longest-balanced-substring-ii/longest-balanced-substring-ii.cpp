class Solution
{
public:

    int long1(string s)
    {
        char c = s[0];
        int index = 0;
        int ans = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(c == s[i])
            {
                ans = max(ans, i - index + 1);
            }
            else
            {
                index = i;
                c = s[i];
            }
        }
        return ans;
    }

    int long2(string s, char c1, char c2)
    {
        int x = 0;
        int y = 0;
        int ans = 0;
        unordered_map<int,int> mpp;

        mpp[0] = -1;   // FIX: base case

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != c1 && s[i] != c2)
            {
                x = 0;
                y = 0;
                mpp.clear();      // reset map for new segment
                mpp[0] = i;       // FIX: reset base correctly
            }
            else
            {
                if(s[i] == c1)
                    x++;
                else
                    y++;

                int dif = y - x;

                if(mpp.find(dif) != mpp.end())
                {
                    ans = max(ans, i - mpp[dif]);
                }
                else
                {
                    mpp[dif] = i;   // FIX: store first occurrence only
                }
            }
        }
        return ans;
    }

    int long3(string s)
    {
        int x = 0;
        int y = 0;
        int z = 0;
        unordered_map<string,int> mpp;
        int ans = 0;

        mpp["0#0"] = -1;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
                x++;
            else if(s[i] == 'b')
                y++;
            else
                z++;

            int dif1 = y - x;
            int dif2 = z - y;

            string temp = to_string(dif1) + "#" + to_string(dif2);

            if(mpp.find(temp) != mpp.end())
            {
                ans = max(ans, i - mpp[temp]);
            }
            else
            {
                mpp[temp] = i;
            }
        }
        return ans;
    }

    int longestBalanced(string s)
    {
        int ans = 0;

        ans = max(ans, long1(s));
        ans = max({ ans,
                    long2(s,'a','b'),
                    long2(s,'b','c'),
                    long2(s,'c','a') });

        ans = max(ans, long3(s));

        return ans;
    }
};
