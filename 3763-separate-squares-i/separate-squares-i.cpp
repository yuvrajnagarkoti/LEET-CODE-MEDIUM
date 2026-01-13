class Solution {
public:
    double separateSquares(vector<vector<int>>& squares)
    {
        double low = squares[0][1], high = squares[0][1] + squares[0][2];

        for (int i = 0; i < squares.size(); i++)
        {
            if (low > squares[i][1])
                low = squares[i][1];
            if (high < squares[i][1] + squares[i][2])
                high = squares[i][1] + squares[i][2];
        }

        // FIX: use precision-based loop instead of low <= high
        for (int iter = 0; iter < 60; iter++)
        {
            double mid = low + (high - low) / 2.0;
            double downa = 0, upa = 0;

            for (int i = 0; i < squares.size(); i++)
            {
                double y = squares[i][1];
                double l = squares[i][2];

                // FIX: correct area calculation (width * height)
                double h_down = max(0.0, min(l, mid - y));          // FIX
                double h_up   = max(0.0, min(l, (y + l) - mid));    // FIX

                downa += l * h_down;   // FIX
                upa   += l * h_up;     // FIX
            }

            // FIX: binary search must move using mid, not ++ / --
            if (downa < upa)
                low = mid;     // FIX
            else
                high = mid;    // FIX
        }

        return low; // FIX: return converged value
    }
};
