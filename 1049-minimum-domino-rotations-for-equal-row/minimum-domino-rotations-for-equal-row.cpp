class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms)
    {
        int rotateTop = 0, rotateBottom = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != target && bottoms[i] != target)
            {
                return -1;
            }
            if (tops[i] != target)
                rotateTop++;
            if (bottoms[i] != target)
                rotateBottom++;
        }
        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;
        if (tops[0] != bottoms[0])
        {
            return check(bottoms[0], tops, bottoms);
        }
        return -1;
    }
};
