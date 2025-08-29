class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        int i = 0, j = 0, k = 0;
        map<char, string> mpp;
        map<string, char> rev;
        while (i < s.length() && k < pattern.size())
        {
            while (i < s.length() && s[i] == ' ')
                i++;

            j = i;
            while (j < s.length() && s[j] != ' ')
                j++;

            string temp = s.substr(i, j - i);

            // check char → word
            auto it = mpp.find(pattern[k]);
            if (it != mpp.end() && it->second != temp)
                return false;

            // check word → char
            auto it2 = rev.find(temp);
            if (it2 != rev.end() && it2->second != pattern[k])
                return false;

            // assign both mappings
            mpp[pattern[k]] = temp;
            rev[temp] = pattern[k];

            k++;
            i = j;
        }

        // both must be fully consumed
        return (k == pattern.size() && i >= s.length());
    }
};
