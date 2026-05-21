class Solution
{
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_set<string> st;

        // Store all prefixes from arr1
        for(int x : arr1)
        {
            string s = to_string(x);
            string prefix = "";

            for(char c : s)
            {
                prefix += c;
                st.insert(prefix);
            }
        }

        int ans = 0;

        // Check prefixes from arr2
        for(int x : arr2)
        {
            string s = to_string(x);
            string prefix = "";

            for(char c : s)
            {
                prefix += c;

                if(st.count(prefix))
                {
                    ans = max(ans, (int)prefix.length());
                }
            }
        }

        return ans;
    }
};