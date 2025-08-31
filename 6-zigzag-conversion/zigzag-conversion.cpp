class Solution {
public:
    string convert(string s, int rows)
    {
        if (rows == 1 || rows >= s.size()) return s;

        vector<string> temp(rows, "");
        int i = 0, step = 1; // start at row 0, going down

        for (char ch : s)
        {
            temp[i] += ch;
            if (i == 0) step = 1;            // change direction: go down
            else if (i == rows - 1) step = -1; // change direction: go up
            i += step;
        }

        string ans;
        for (auto &it : temp) ans += it;
        return ans;
    }
};
