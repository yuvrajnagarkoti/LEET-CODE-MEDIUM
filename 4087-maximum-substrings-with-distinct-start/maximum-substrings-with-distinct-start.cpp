class Solution {
public:
    int maxDistinct(string s)
    {
        set<char> s1;
        for(char c : s)
            s1.insert(c);
        return s1.size();
    }
};