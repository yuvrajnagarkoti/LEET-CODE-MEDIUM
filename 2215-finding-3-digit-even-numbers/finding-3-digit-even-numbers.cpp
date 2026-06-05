class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        sort(digits.begin(),digits.end());
        set<int> st;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j)
                        continue;
                    st.insert( (digits[i]*100)+(digits[j]*10)+(digits[k]));
                }
            }
        }
        vector<int> ans;
        for(auto s : st)
        {
            if(s >= 100 && s%2==0)
            {
                ans.push_back(s);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};