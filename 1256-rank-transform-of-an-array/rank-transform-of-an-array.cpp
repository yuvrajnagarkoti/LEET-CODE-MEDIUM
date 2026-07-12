class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return arr;
        
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> rank;
        int r = 1;
        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] != sorted[i-1]) {
                rank[sorted[i]] = r++;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};