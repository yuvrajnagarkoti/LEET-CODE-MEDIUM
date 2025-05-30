class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        vector<int> top(7, 0);
        vector<int> bottom(7, 0);
        vector<int> same(7, 0);
        int n = tops.size();
           
        for(int i=0; i < tops.size(); i++)
        {
            top[tops[i]] ++;
            bottom[bottoms[i]]++;
            if(tops[i] == bottoms[i])
            {
                same[tops[i]]++;
            }
        }
        
        for(int i=1; i<7; i++)
        {
            if(top[i] + bottom[i] - same[i] == n)
            {
                return n - max(top[i], bottom[i]);
            }
        } 
        return -1;
    }
};