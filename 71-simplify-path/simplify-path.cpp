class Solution {
public:
    string simplifyPath(string path)
    {
        stack<string> stk;
        string cur = "";

        for (int i = 0; i <= path.size(); i++)
        {
            if (i == path.size() || path[i] == '/')
            {
                if (cur == "" || cur == ".")
                {
                    // do nothing
                }
                else if (cur == "..")
                {
                    if (!stk.empty())
                        stk.pop();
                }
                else
                {
                    stk.push(cur);
                }
                cur.clear();
            }
            else
            {
                cur.push_back(path[i]);
            }
        }

        if (stk.empty())
            return "/";

        string ans = "";
        while (!stk.empty())
        {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
