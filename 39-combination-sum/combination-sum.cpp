class Solution
{
    public:
    vector<vector<int>> ans;
    void rec(int k,vector<int> temp,int sum,vector<int>& candidates, int target)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if(k+1 < candidates.size())
            rec(k+1,temp,sum,candidates,target);
        
        if(sum < target)
        {
            temp.push_back(candidates[k]);
            sum = sum + candidates[k];
            rec(k,temp,sum,candidates,target);
            temp.pop_back();
            sum = sum - candidates[k];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int sum=0;
        vector<int> temp;
        rec(0,temp,sum,candidates,target);
        return ans;
    }
};