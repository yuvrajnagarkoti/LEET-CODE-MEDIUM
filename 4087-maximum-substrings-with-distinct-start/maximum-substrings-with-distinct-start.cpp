class Solution {
public:
    int maxDistinct(string s) {
        int hash[26] = {0};
        for(char ch : s)
        {

            hash[ch-97] = 1;
        }
        int ans = 0;
        for(int i : hash)
        {
            ans += i ;
        }
        return ans;
    }
};