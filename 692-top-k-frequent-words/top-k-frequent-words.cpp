class Solution {
public:
    vector<string> topKFrequent(vector<string>& word, int k)
    {
        unordered_map<string,int> mpp;

        for(auto s : word)
            mpp[s]++;

        vector<string> ans;

        for(auto it : mpp)
            ans.push_back(it.first);

        sort(ans.begin(), ans.end(), [&](string a, string b)
        {
            if(mpp[a] == mpp[b])
                return a < b;

            return mpp[a] > mpp[b];
        });

        ans.resize(k);

        return ans;
    }
};