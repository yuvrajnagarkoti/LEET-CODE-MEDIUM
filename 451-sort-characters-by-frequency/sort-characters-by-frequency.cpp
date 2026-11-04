class Solution {
public:
    string frequencySort(string s)
    {
        map<char,int> mpp;

        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }

        vector<pair<char,int>> v;

        for(auto it : mpp)
        {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](auto a, auto b)
        {
            return a.second > b.second;
        });

        string ans = "";

        for(auto it : v)
        {
            int count = it.second;
            char c = it.first;

            while(count--)
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};