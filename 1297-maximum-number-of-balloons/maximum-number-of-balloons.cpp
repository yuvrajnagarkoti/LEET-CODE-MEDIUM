class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        map<char,int> mpp;
        int ans=INT_MAX;
        for(char ch : text)
        {
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            {
                mpp[ch]++;
            }
            
        }
        mpp['l']=mpp['l']/2;
        mpp['o']=mpp['o']/2;

        for(char it : string("balon"))
        {
            ans = min(ans,mpp[it]);
        }
        return ans;
    }
};