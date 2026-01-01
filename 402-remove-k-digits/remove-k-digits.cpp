class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<char> stk;
        int n = num.length();
        if (k == n)
            return "0";

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && stk.top() > num[i] && k > 0)
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        // remove remaining digits if k > 0
        while (k > 0 && !stk.empty())
        {
            stk.pop();
            k--;
        }

        string ans = "";
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0')
            idx++;

        ans = ans.substr(idx);

        return ans == "" ? "0" : ans;
    }
};
