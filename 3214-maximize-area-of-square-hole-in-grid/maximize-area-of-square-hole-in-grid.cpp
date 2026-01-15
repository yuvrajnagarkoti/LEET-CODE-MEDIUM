class Solution {
public:
    int longestConsecutive(vector<int>& bars)
    {
        if (bars.empty()) return 0;

        sort(bars.begin(), bars.end());

        int maxLen = 1;
        int curr = 1;

        for (int i = 1; i < bars.size(); i++)
        {
            if (bars[i] == bars[i - 1] + 1)
            {
                curr++;
            }
            else
            {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }
        return maxLen;
    }

    int maximizeSquareHoleArea(int n, int m,vector<int>& hBars,vector<int>& vBars)
    {
        int maxH = longestConsecutive(hBars) + 1;
        int maxV = longestConsecutive(vBars) + 1;

        int side = min(maxH, maxV);
        return side * side;
    }
};
