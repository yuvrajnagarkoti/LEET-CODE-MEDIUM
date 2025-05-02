class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = dominoes;
        vector<int> force(n, 0);
        
        int f = 0;
        // Left to right
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') f = n;
            else if (dominoes[i] == 'L') f = 0;
            else f = max(f - 1, 0);
            force[i] += f;
        }

        f = 0;
        // Right to left
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') f = n;
            else if (dominoes[i] == 'R') f = 0;
            else f = max(f - 1, 0);
            force[i] -= f;
        }

        for (int i = 0; i < n; ++i) {
            if (force[i] > 0) ans[i] = 'R';
            else if (force[i] < 0) ans[i] = 'L';
            else ans[i] = '.';
        }

        return ans;
    }
};
