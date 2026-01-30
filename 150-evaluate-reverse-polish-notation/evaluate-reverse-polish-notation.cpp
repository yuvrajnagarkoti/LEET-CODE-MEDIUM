class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack <string> stk;
        for(int i=0;i<tokens.size();i++)
        {
            string ch = tokens[i];
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int first=stoi(stk.top()); stk.pop();
                int second=stoi(stk.top()); stk.pop();
                int ans = 0;
                if( ch == "+")
                    ans = first + second;
                else if(ch == "-")
                    ans = second - first;
                else if(ch == "*")
                    ans = first * second;
                else
                    ans = second / first;
                
                stk.push(to_string(ans));
            }
            else
            {
                stk.push(ch);
            }
        }
        return stoi(stk.top());
    }
};