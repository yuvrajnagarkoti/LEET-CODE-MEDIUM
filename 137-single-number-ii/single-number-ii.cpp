class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map <int,int> count;
        for(int it : nums)
        {
            count[it]++;
        }
        for(auto it : count)
        {
            if(it.second != 3)
            {
                return it.first;
            }
        }
        return 0;
    }
};