class Solution
{
    public:
    vector<vector<int>> ans;
    void rec(int idx, vector<int>& temp, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Don't take current element
        rec(idx + 1, temp, candidates, target);

        // Take current element
        temp.push_back(candidates[idx]);
        rec(idx, temp, candidates, target - candidates[idx]);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> temp;
        rec(0, temp, candidates, target);
        return ans;
    }
};