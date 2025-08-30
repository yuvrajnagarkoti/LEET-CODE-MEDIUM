class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int ans=0;
        for(int k=0;k<1001;k++)
        {
            int count=0;
            for(int i=0;i<citations.size();i++)
            {
                if(citations[i] >= k)
                    count++;
            }
            if(count >= k)
                ans=k;
            else
                break;
        }
        return ans;
    }
};