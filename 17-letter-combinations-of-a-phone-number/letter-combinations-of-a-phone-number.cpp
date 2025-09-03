class Solution {
public:
    vector<string> letterCombinations(string digit)
    {
        vector<string> ans;
        vector<vector<char>> mpp =
        {
            {}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
            {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'},
            {'t','u','v'}, {'w','x','y','z'}
        };

        int n = digit.size();
        if(n==0) return ans;

        if(n==1) {
            int d = digit[0]-'0';
            for(char c : mpp[d]) ans.push_back({c});
        }
        else if(n==2) {
            int d1 = digit[0]-'0';
            int d2 = digit[1]-'0';
            for(char c1 : mpp[d1])
                for(char c2 : mpp[d2])
                    ans.push_back(string()+c1+c2);
        }
        else if(n==3) {
            int d1 = digit[0]-'0';
            int d2 = digit[1]-'0';
            int d3 = digit[2]-'0';
            for(char c1 : mpp[d1])
                for(char c2 : mpp[d2])
                    for(char c3 : mpp[d3])
                        ans.push_back(string()+c1+c2+c3);
        }
        else if(n==4) {
            int d1 = digit[0]-'0';
            int d2 = digit[1]-'0';
            int d3 = digit[2]-'0';
            int d4 = digit[3]-'0';
            for(char c1 : mpp[d1])
                for(char c2 : mpp[d2])
                    for(char c3 : mpp[d3])
                        for(char c4 : mpp[d4])
                            ans.push_back(string()+c1+c2+c3+c4);
        }
        return ans;
    }
};
