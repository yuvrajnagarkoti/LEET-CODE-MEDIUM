class Solution {
public:
    string frequencySort(string s)
    {
        vector<int> freq(256, 0);
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<char, int>> vec;
        for (int i = 0; i < 256; ++i) {
            if (freq[i] > 0) {
                vec.push_back({(char)i, freq[i]});
            }
        }
        sort(vec.begin(),vec.end(),[](const pair <char,int> &a,const pair <char,int> &b)
        {
            return a.second > b.second;
        });
        string result;
        for (auto& p : vec) {
            result.append(p.second, p.first);
        }
        return result;
    }
};
