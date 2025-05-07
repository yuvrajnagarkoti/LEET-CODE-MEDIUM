class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int i,j;
        vector <int> ans;
        for(i=0;i<boxes.length();i++)
        {
            int sum=0;
            for(j=0;j<boxes.length();j++)
            {
                if(j != i)
                {
                    if(boxes[j] == '1')
                    {
                        sum = sum + abs(j-i);
                    }
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};