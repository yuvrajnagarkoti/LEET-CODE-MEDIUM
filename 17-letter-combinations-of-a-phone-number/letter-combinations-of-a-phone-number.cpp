class Solution {
public:
    vector<string> letterCombinations(string digit)
    {
        vector<string> ans;
        vector<vector<char>> mpp;
        mpp.push_back({});
        mpp.push_back({});
        mpp.push_back({'a','b','c'});
        mpp.push_back({'d','e','f'});
        mpp.push_back({'g','h','i'});
        mpp.push_back({'j','k','l'});
        mpp.push_back({'m','n','o'});
        mpp.push_back({'p','q','r','s'});
        mpp.push_back({'t','u','v'});
        mpp.push_back({'w','x','y','z'});

        int n=digit.size();
        if(n==1)
        {
            int d = digit[0]-'0';
            for(int i=0;i<mpp[d].size();i++ )
                ans.push_back({mpp[d][i]});
        }
        else if(n==2)
        {
            int d1= digit[0]-'0';
            int d2= digit[1]-'0';
            for(int i=0;i<mpp[d1].size();i++)
            {
                string temp = "";
                temp = temp +mpp[d1][i];
                for(int j=0;j<mpp[d2].size();j++)
                {
                    ans.push_back(temp+mpp[d2][j]);
                }
            }
        }
        else if(n==3)
        {
            int d1= digit[0]-'0';
            int d2= digit[1]-'0';
            int d3= digit[2]-'0';
            for(int i=0;i<mpp[d1].size();i++)
            {
                string temp = "";
                temp+=mpp[d1][i];
                for(int j=0;j<mpp[d2].size();j++)
                {
                    string t1=temp+mpp[d2][j];
                    for(int k=0;k<mpp[d3].size();k++)
                    {
                        ans.push_back(t1+mpp[d3][k]);
                    }
                }
            }
        }
        else if(n==4)
        {
            int d1= digit[0]-'0';
            int d2= digit[1]-'0';
            int d3= digit[2]-'0';
            int d4= digit[3]-'0';
            for(int i=0;i<mpp[d1].size();i++)
            {
                string temp = "";
                temp+=mpp[d1][i];
                for(int j=0;j<mpp[d2].size();j++)
                {
                    string t1=temp+mpp[d2][j];
                    for(int k=0;k<mpp[d3].size();k++)
                    {
                        string t2=t1+mpp[d3][k];
                        for(int l=0;l<mpp[d4].size();l++)
                        {
                            ans.push_back(t2+mpp[d4][l]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};