class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b)
    {
        int count=0;
        set<int> s1;
        set<int> s2;
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            s1.insert(a[i]);
            s2.insert(b[i]);
            if(a[i] != b[i])
            {
                if(s1.find(a[i]) !=s1.end() && s2.find(a[i]) != s2.end())
                count++;
                if(s1.find(b[i]) !=s1.end() && s2.find(b[i]) != s2.end())
                count++;
            }
            else
            {
                count++;
            }

            ans.push_back(count);
        }
        return ans;
    }
};