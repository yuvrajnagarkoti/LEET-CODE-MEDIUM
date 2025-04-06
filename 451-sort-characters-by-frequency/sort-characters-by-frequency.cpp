class Solution {
public:
    string frequencySort(string s)
    {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        // Step 2: Put characters and their frequency into a vector
        vector<pair<char, int>> vec(freq.begin(), freq.end());
        // Step 3: Sort the vector by frequency (descending)
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        // Step 4: Build the result string
        string result;
        for (auto& p : vec)
        {
            result.append(p.second, p.first);
        }
        return result;
    }
};
