class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int prev=-1,i=0;
        while(i<dominoes.size())
        {
            if(dominoes[i]!='.')
            {
                prev=i;
                i++;
                continue;
            }
            int cur=i;
            while(i<dominoes.size()&&dominoes[i]=='.') i++;
            if(prev==-1||dominoes[prev]=='L')
            {
                if(i<dominoes.size()&&dominoes[i]=='L')
                {
                    while(cur<i)
                    {
                        dominoes[cur]='L';
                        cur++;
                    }
                }
            }
            else
            {
                if(i>=dominoes.size()||dominoes[i]=='R')
                {
                    while(cur<i)
                    {
                        dominoes[cur]='R';
                        cur++;
                    }
                }
                else
                {
                    while(cur<i)
                    {
                        int val1=cur-prev,val2=i-cur;
                        if(val1<val2) dominoes[cur]=dominoes[prev];
                        else if(val1>val2) dominoes[cur]=dominoes[i];
                        cur++;
                    }
                }    
            }
            prev=i;
            i++;
        }
        return dominoes;
    }
};