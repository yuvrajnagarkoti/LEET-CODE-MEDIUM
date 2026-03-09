class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int>& candidates, int target, int cursum,
             vector<int>& curarr, int index) {
        int n = candidates.size();

        if (cursum > target)
            return;

        if (cursum == target) {
            ans.push_back(curarr);
            return;
        }

        if (index >= n)
            return;

        curarr.push_back(candidates[index]);
        rec(candidates, target, cursum + candidates[index], curarr, index + 1);
        curarr.pop_back();

        while (index + 1 < n && candidates[index] == candidates[index + 1])
            index++;

        rec(candidates, target, cursum, curarr, index + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curarr;
        rec(candidates, target, 0, curarr, 0);

        return ans;
    }
};