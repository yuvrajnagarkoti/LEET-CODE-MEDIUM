class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);

        // Count balls and steps from the left side
        int ballsOnLeft = 0;
        int movesFromLeft = 0;
        for (int i = 0; i < n; i++)
        {
            ans[i] += movesFromLeft;          // Add moves needed from the left
            ballsOnLeft += boxes[i] - '0';       // Count balls at current position (if any)
            movesFromLeft += ballsOnLeft;        // Update total moves from the left
        }

        // Count balls and steps from the right side
        int ballsOnRight = 0;
        int movesFromRight = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] += movesFromRight;         // Add moves needed from the right
            ballsOnRight += boxes[i] - '0';      // Count balls at current position (if any)
            movesFromRight += ballsOnRight;      // Update total moves from the right
        }
        return ans;
    }
};
