class Solution {
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        string ans;
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n) break;

            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            string temp = s.substr(i, j - i);
            reverse(temp.begin(), temp.end());

            if (!ans.empty()) ans += " ";
            ans += temp;

            i = j;
        }
        return ans;
    }
};
